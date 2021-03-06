﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;
using System;
using UnityEngine.Networking;
using UnityEngine.UI;

/// <summary>
/// 인 게임에서 전반적인 데이터 처리를 담당하며 서버와 데이터를 받으면서 해당 데이터를 분배 합니다.
/// 주로 서버와 통신, 카멜파 이동 처리를 담당합니다.
/// </summary>
public class ObjectManager : MonoBehaviour
{
    public static ObjectManager Instance = null;
    public InGameCamera Camera;
    public PlayerManager PlayerManage;

    void Awake() {
        if (Instance == null)
        {
            if (PlayerInit())
            {
                StartCoroutine(ServerRequest());
            }
            Instance = this;
        }
        else
        {
            Destroy(this.gameObject);
        }
    }

    bool PlayerInit()
    {
        bool Result = true;
        if (NetworkManager.ClientNetworkId == null)
        {
            NetworkManager.ClientNetworkId = 0;
            NetworkManager.ClientName = "Offline";
            PlayerManage.AddPlayer(0, 0, "Offline", 0);

            Result = false;
        }

        if (Result)
        {
            try
            {
                Packet.Room room = Packet.Room.Parser.ParseJson(PlayerPrefs.GetString("UserList"));

                foreach (var item in room.RoomUsers)
                {
                    PlayerManage.AddPlayer(0, new Vector2(item.Position.X, item.Position.Y), item.Name, item.NetworkId);
                }
            }
            catch (Exception)
            {
                NetworkManager.ClientNetworkId = 0;
                NetworkManager.ClientName = "Offline";
                PlayerManage.AddPlayer(0, 0, "Offline", 0);
                Result = false;
            }
        }
        PlayerPrefs.DeleteKey("UserList");
        PlayerManage.Initialize();
        return Result;
    }

    /// <summary>
    /// 이것을 이제 개인 클라이언트에게 값을 던져줘야함.
    /// </summary>
    IEnumerator ServerRequest(){
        float T1 = Time.time, T2;
        while (true)
        {
            var Que = NetworkManager.Instance.ServerRequest(PlayerManage.ClientPlayer.transform.position);
            while (Que.Count != 0)
            {
                var info = Que.Dequeue();
                if (info.Type == Packet.Type.MoveAck)
                {
                    Packet.MoveAck moveAck = Packet.MoveAck.Parser.ParseFrom(info.Payload);
                    Vector4 data = new Vector4(moveAck.Position.X, moveAck.Position.Y, moveAck.Position.Z)
                    {
                        w = moveAck.NetworkId
                    };
                    PlayerManage.MovementQueue.Enqueue(data);
                }
                else if (info.Type == Packet.Type.CastSkillAck)
                {
                    Packet.CastSkillAck castSkill = Packet.CastSkillAck.Parser.ParseFrom(info.Payload);
                    if (SkillManager.IsActiveSkill(castSkill.SkillId))
                    {
                        var skill = (SkillInfo.Insatence[castSkill.SkillId] as ActiveSkill);
                        skill.CastPosition = new Vector2
                        {
                            x = castSkill.CastPosition.X,
                            y = castSkill.CastPosition.Y
                        };
                        skill.CastDirection = new Vector2
                        {
                            x = castSkill.CastDirection.X,
                            y = castSkill.CastDirection.Y,
                        };
                        skill.NetworkId = castSkill.NetworkId;
                        PlayerManage.CastSkill(skill);
                    }
                }
                else if (info.Type == Packet.Type.CastSkillHitAck)
                {
                    var castHitSkill = Packet.CastSkillHitAck.Parser.ParseFrom(info.Payload);
                    var skill = SkillInfo.Insatence[castHitSkill.SkillId];
                    skill.NetworkId = castHitSkill.NetworkId;
                    Debug.Log($"Type : {skill.NetworkId}");
                    PlayerManage.CastHitSkill(skill);
                }
                else if (info.Type == Packet.Type.EnterNewRoomUserAck)
                {
                    Packet.EnterNewRoomUserAck enter = Packet.EnterNewRoomUserAck.Parser.ParseFrom(info.Payload);
                    PlayerManage.AddPlayer(0, 0, enter.NewUser.Name, enter.NewUser.NetworkId);
                    Debug.Log("새로운 유저 입장");
                }
                else if (info.Type == Packet.Type.Disconnect
                    || info.Type == Packet.Type.ExitRoomUserAck
                    || info.Type == Packet.Type.LogoutAck)
                {
                    Packet.Disconnect disconnect = Packet.Disconnect.Parser.ParseFrom(info.Payload);
                    PlayerManage.DelPlayer(disconnect.NetworkId);
                }
                else
                {
                    Debug.Log(info.Type);
                }
            }
            T2 = Time.time;
            int ping = 0;
            if ((T2 - T1) != 0)
            {
                ping = (int)(1.0f / (T2 - T1));
            }
            T1 = Time.time;

            PlayerManage.OnChangePing(ping);
            yield return new WaitForSeconds(0.001f);
        }
    }


    private void FixedUpdate()
    {
        if (NetworkManager.ClientNetworkId != null)
        {
            Camera.Target = PlayerManage.ClientPlayer.transform.position;
            Camera.NeedSize = PlayerManage.LocationCamera;
        }
    }
}
