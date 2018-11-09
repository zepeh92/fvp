﻿using System.Collections;
using System.Collections.Generic;
using System;

using UnityEngine;


public delegate void ChangeStatus(float now, float max);
public class Character : MonoBehaviour
{
    // 이벤트
    public event ChangeStatus ChangeHP;
    public event ChangeStatus ChangeMP;

    // 이벤트 발생 시키는 함수
    // 체력이 변화 가 되었을 경우 UI에 변화를 주어야함.
    void OnChangeHP(float old, float now)
    {
        if (ChangeHP != null)
            ChangeHP.Invoke(old, now);
    }
    // 기력이 변화가 되었을 경우에 UI에 변화를 주는 함수.
    void OnChangeMP(float old, float now)
    {
        if (ChangeMP != null)
            ChangeMP.Invoke(old, now);
    }

    // 캐릭터가 이동할 수 있는 최대 속도.
    public float MaxSpeed;
    // 점프하는 힘
    public float Jump;
    // 캐릭터가 이동하는 가속도
    public float Accelerate;
    // 현재 속도
    public float Speed;

    public float MaxHP = 100.0f;
    public float HP
    {
        get
        {
            return _HP;
        }
        set
        {
            if (value > MaxHP)
            {
                value = MaxHP;
            }
            else if (value < 0)
            {
                value = 0;
            }
            if (value != _HP)
            {
                OnChangeHP(value, MaxHP);
                _HP = value;
            }
        }
    }

    public float MaxMP = 100.0f;
    public float MP
    {
        get
        {
            return _MP;
        }
        set
        {
            if (value > MaxMP)
            {
                value = MaxMP;
            }
            else if (value < 0)
            {
                value = 0;
            }
            if (value != _MP)
            {
                OnChangeMP(value, MaxMP);
                _MP = value;
            }
        }
    }

    // Components
    Animator anime;
    Rigidbody2D rigidBody;
    SpriteRenderer Renderer;

    // 고유 정보
    public int? UID = null;
    
    // 현재 스테이터스
    private float _HP = 100.0f;
    private float _MP = 100.0f;

    // 젤 처음 프로그램 실행이 될 코드. 각 캐릭터의 고유 정보를 가져옴.
    void Awake()
    {
        UID = this.GetHashCode();
    }

    // 실행이 되면은 각 컴포넌트의 정보를 가져옴.
    void Start()
    {
        anime = GetComponent<Animator>();
        rigidBody = GetComponent<Rigidbody2D>();
        Renderer = GetComponent<SpriteRenderer>();
    }

    // 2번째의 RigidBody가 속도에 따라서 Jump 인지 Down인지 체크함.
    private void OnTriggerExit2D(Collider2D collision)
    {
        if (rigidBody.velocity.y > 0)
        {
            Debug.Log("공중부양상태");
            anime.SetBool("Jump", true);
        }
        else if (rigidBody.velocity.y < 0)
        {
            anime.SetBool("Down", true);
        }
    }

    // RigidBody의 레이어가 무엇이냐에 따라서 상태 전이
    private void OnTriggerEnter2D(Collider2D collision)
    {
        Debug.Log("Attach" + collision.gameObject.layer);
        if (collision.gameObject.layer == 8)
        {
            anime.SetBool("Jump", false);
            anime.SetBool("Down", false);
        }
    }

    // FixedUpdate에서 처리하지 않고
    // 독자적인 Movement에서 처리를 함.
    // PlayerManager의 FixedUpdate에 종속됨.
    public void Movement(Vector4 data)
    {
        // InputManager은 인게임내 스마트폰에 있는
        // 가상 스틱의 값을 나타냄
        float x = InputManager.InputVector.x;
        float y = InputManager.InputVector.y;
        // data.z는 키보드의 값을 받을것인지 스마트폰의 입력을 받을것인지 나타냄
        // data.z 값의 편집 방법은 Hierarchy의 PlayerManager의 Is Debug의 값을 수정 요함.

        if (data.z != 0)
        {
            x = data.x;
            y = data.y;
        }
        
        // 애니메이션 이동 방향의 값 
        anime.SetFloat("DivX", x);
        anime.SetFloat("DivY", y);

        // 캐릭터의 이동 함수
        float Acc = Accelerate * Time.deltaTime;
        // 이동관련 함수 처리
        #region Move
        if (x < 0)
        {
            // 이동시 MP 10 소모 (초당)
            MP -= 10 * Time.deltaTime;
            if (Speed < -MaxSpeed)
            {
                Speed = -MaxSpeed;
            }
            else
            {
                Speed -= Acc;
            }
        }
        else if (x > 0)
        {
            // 이동시 MP 10 소모 (초당)
            MP -= 10 * Time.deltaTime;
            if (Speed > MaxSpeed)
            {
                Speed = MaxSpeed;
            }
            else
            {
                Speed += Acc;
            }
        }
        else
        {
            // x의 값이 0 일 때 멈추는 효과
            if (Speed > 0.05)
            {
                Speed -= Acc * 1.3f;
            }
            else if (Speed < -0.05)
            {
                Speed += Acc * 1.3f;
            }
            else
            {
                Speed = 0.0f;
            }
        }
        #endregion

        // 현재 이동하는 속도에 따른 애니메이션 효과 반전
        if (Speed > 0)
        {
            Renderer.flipX = true;
        }
        else if (Speed < 0)
        {
            Renderer.flipX = false;
        }

        // 현재 속도를 체크하여 걷고 있는지 아닌지 설정
        if (Speed != 0.0f)
        {
            anime.SetBool("Walking", true);
        }
        else
        {
            anime.SetBool("Walking", false);
        }

        // 점프 처리 하는 코드
        // 현재 점프중인지 아닌지 체크를 함
        if (!anime.GetBool("Jump"))
        {
            // 키보드의 입력시 절대적으로 1.0f로 고정
            // 가상 스틱을 이용시 80% 가량 위로 이동해야지만 처리
            if (y > 0.8f)
            {
                // MP 30을 소모하므로 30 이상일 경우만
                if (MP >= 30)
                {
                    // MP 30을 낮추고
                    MP -= 30;
                    // 현재 y축의 이동속도를 0로 바꿉니다.
                    rigidBody.velocity = new Vector2(rigidBody.velocity.x, 0);
                    // 점프하는 힘을 줍니다.
                    rigidBody.AddForce(new Vector2(0, Jump));
                    // 점프 애니메이션 설정.
                    anime.SetBool("Jump", true);
                }
            }
        }
        // 초당 MP는 15씩 증가하는 코드.
        MP += Time.deltaTime * 15;

        // 그외 변화된 좌우 값을 설정합니다.
        rigidBody.transform.Translate(Vector3.right * Speed);
    }
}
