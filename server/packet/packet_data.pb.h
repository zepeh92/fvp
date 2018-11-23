// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: packet_data.proto

#ifndef PROTOBUF_INCLUDED_packet_5fdata_2eproto
#define PROTOBUF_INCLUDED_packet_5fdata_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_packet_5fdata_2eproto 

namespace protobuf_packet_5fdata_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_packet_5fdata_2eproto
namespace packet {
class Room;
class RoomDefaultTypeInternal;
extern RoomDefaultTypeInternal _Room_default_instance_;
class RoomUser;
class RoomUserDefaultTypeInternal;
extern RoomUserDefaultTypeInternal _RoomUser_default_instance_;
class Vector3;
class Vector3DefaultTypeInternal;
extern Vector3DefaultTypeInternal _Vector3_default_instance_;
}  // namespace packet
namespace google {
namespace protobuf {
template<> ::packet::Room* Arena::CreateMaybeMessage<::packet::Room>(Arena*);
template<> ::packet::RoomUser* Arena::CreateMaybeMessage<::packet::RoomUser>(Arena*);
template<> ::packet::Vector3* Arena::CreateMaybeMessage<::packet::Vector3>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace packet {

// ===================================================================

class Vector3 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:packet.Vector3) */ {
 public:
  Vector3();
  virtual ~Vector3();

  Vector3(const Vector3& from);

  inline Vector3& operator=(const Vector3& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Vector3(Vector3&& from) noexcept
    : Vector3() {
    *this = ::std::move(from);
  }

  inline Vector3& operator=(Vector3&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Vector3& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Vector3* internal_default_instance() {
    return reinterpret_cast<const Vector3*>(
               &_Vector3_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Vector3* other);
  friend void swap(Vector3& a, Vector3& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Vector3* New() const final {
    return CreateMaybeMessage<Vector3>(NULL);
  }

  Vector3* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Vector3>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Vector3& from);
  void MergeFrom(const Vector3& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Vector3* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // float x = 1;
  void clear_x();
  static const int kXFieldNumber = 1;
  float x() const;
  void set_x(float value);

  // float y = 2;
  void clear_y();
  static const int kYFieldNumber = 2;
  float y() const;
  void set_y(float value);

  // float z = 3;
  void clear_z();
  static const int kZFieldNumber = 3;
  float z() const;
  void set_z(float value);

  // @@protoc_insertion_point(class_scope:packet.Vector3)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  float x_;
  float y_;
  float z_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_packet_5fdata_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class RoomUser : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:packet.RoomUser) */ {
 public:
  RoomUser();
  virtual ~RoomUser();

  RoomUser(const RoomUser& from);

  inline RoomUser& operator=(const RoomUser& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RoomUser(RoomUser&& from) noexcept
    : RoomUser() {
    *this = ::std::move(from);
  }

  inline RoomUser& operator=(RoomUser&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RoomUser& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RoomUser* internal_default_instance() {
    return reinterpret_cast<const RoomUser*>(
               &_RoomUser_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(RoomUser* other);
  friend void swap(RoomUser& a, RoomUser& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RoomUser* New() const final {
    return CreateMaybeMessage<RoomUser>(NULL);
  }

  RoomUser* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<RoomUser>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const RoomUser& from);
  void MergeFrom(const RoomUser& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RoomUser* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 3;
  void clear_name();
  static const int kNameFieldNumber = 3;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // .packet.Vector3 position = 2;
  bool has_position() const;
  void clear_position();
  static const int kPositionFieldNumber = 2;
  private:
  const ::packet::Vector3& _internal_position() const;
  public:
  const ::packet::Vector3& position() const;
  ::packet::Vector3* release_position();
  ::packet::Vector3* mutable_position();
  void set_allocated_position(::packet::Vector3* position);

  // int64 network_id = 1;
  void clear_network_id();
  static const int kNetworkIdFieldNumber = 1;
  ::google::protobuf::int64 network_id() const;
  void set_network_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:packet.RoomUser)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::packet::Vector3* position_;
  ::google::protobuf::int64 network_id_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_packet_5fdata_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Room : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:packet.Room) */ {
 public:
  Room();
  virtual ~Room();

  Room(const Room& from);

  inline Room& operator=(const Room& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Room(Room&& from) noexcept
    : Room() {
    *this = ::std::move(from);
  }

  inline Room& operator=(Room&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Room& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Room* internal_default_instance() {
    return reinterpret_cast<const Room*>(
               &_Room_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(Room* other);
  friend void swap(Room& a, Room& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Room* New() const final {
    return CreateMaybeMessage<Room>(NULL);
  }

  Room* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Room>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Room& from);
  void MergeFrom(const Room& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Room* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .packet.RoomUser room_users = 5;
  int room_users_size() const;
  void clear_room_users();
  static const int kRoomUsersFieldNumber = 5;
  ::packet::RoomUser* mutable_room_users(int index);
  ::google::protobuf::RepeatedPtrField< ::packet::RoomUser >*
      mutable_room_users();
  const ::packet::RoomUser& room_users(int index) const;
  ::packet::RoomUser* add_room_users();
  const ::google::protobuf::RepeatedPtrField< ::packet::RoomUser >&
      room_users() const;

  // string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // int64 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int64 id() const;
  void set_id(::google::protobuf::int64 value);

  // int64 master_user_network_id = 4;
  void clear_master_user_network_id();
  static const int kMasterUserNetworkIdFieldNumber = 4;
  ::google::protobuf::int64 master_user_network_id() const;
  void set_master_user_network_id(::google::protobuf::int64 value);

  // int32 max_user_count = 3;
  void clear_max_user_count();
  static const int kMaxUserCountFieldNumber = 3;
  ::google::protobuf::int32 max_user_count() const;
  void set_max_user_count(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:packet.Room)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::packet::RoomUser > room_users_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int64 id_;
  ::google::protobuf::int64 master_user_network_id_;
  ::google::protobuf::int32 max_user_count_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_packet_5fdata_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Vector3

// float x = 1;
inline void Vector3::clear_x() {
  x_ = 0;
}
inline float Vector3::x() const {
  // @@protoc_insertion_point(field_get:packet.Vector3.x)
  return x_;
}
inline void Vector3::set_x(float value) {
  
  x_ = value;
  // @@protoc_insertion_point(field_set:packet.Vector3.x)
}

// float y = 2;
inline void Vector3::clear_y() {
  y_ = 0;
}
inline float Vector3::y() const {
  // @@protoc_insertion_point(field_get:packet.Vector3.y)
  return y_;
}
inline void Vector3::set_y(float value) {
  
  y_ = value;
  // @@protoc_insertion_point(field_set:packet.Vector3.y)
}

// float z = 3;
inline void Vector3::clear_z() {
  z_ = 0;
}
inline float Vector3::z() const {
  // @@protoc_insertion_point(field_get:packet.Vector3.z)
  return z_;
}
inline void Vector3::set_z(float value) {
  
  z_ = value;
  // @@protoc_insertion_point(field_set:packet.Vector3.z)
}

// -------------------------------------------------------------------

// RoomUser

// int64 network_id = 1;
inline void RoomUser::clear_network_id() {
  network_id_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 RoomUser::network_id() const {
  // @@protoc_insertion_point(field_get:packet.RoomUser.network_id)
  return network_id_;
}
inline void RoomUser::set_network_id(::google::protobuf::int64 value) {
  
  network_id_ = value;
  // @@protoc_insertion_point(field_set:packet.RoomUser.network_id)
}

// .packet.Vector3 position = 2;
inline bool RoomUser::has_position() const {
  return this != internal_default_instance() && position_ != NULL;
}
inline void RoomUser::clear_position() {
  if (GetArenaNoVirtual() == NULL && position_ != NULL) {
    delete position_;
  }
  position_ = NULL;
}
inline const ::packet::Vector3& RoomUser::_internal_position() const {
  return *position_;
}
inline const ::packet::Vector3& RoomUser::position() const {
  const ::packet::Vector3* p = position_;
  // @@protoc_insertion_point(field_get:packet.RoomUser.position)
  return p != NULL ? *p : *reinterpret_cast<const ::packet::Vector3*>(
      &::packet::_Vector3_default_instance_);
}
inline ::packet::Vector3* RoomUser::release_position() {
  // @@protoc_insertion_point(field_release:packet.RoomUser.position)
  
  ::packet::Vector3* temp = position_;
  position_ = NULL;
  return temp;
}
inline ::packet::Vector3* RoomUser::mutable_position() {
  
  if (position_ == NULL) {
    auto* p = CreateMaybeMessage<::packet::Vector3>(GetArenaNoVirtual());
    position_ = p;
  }
  // @@protoc_insertion_point(field_mutable:packet.RoomUser.position)
  return position_;
}
inline void RoomUser::set_allocated_position(::packet::Vector3* position) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete position_;
  }
  if (position) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      position = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, position, submessage_arena);
    }
    
  } else {
    
  }
  position_ = position;
  // @@protoc_insertion_point(field_set_allocated:packet.RoomUser.position)
}

// string name = 3;
inline void RoomUser::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& RoomUser::name() const {
  // @@protoc_insertion_point(field_get:packet.RoomUser.name)
  return name_.GetNoArena();
}
inline void RoomUser::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:packet.RoomUser.name)
}
#if LANG_CXX11
inline void RoomUser::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:packet.RoomUser.name)
}
#endif
inline void RoomUser::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:packet.RoomUser.name)
}
inline void RoomUser::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:packet.RoomUser.name)
}
inline ::std::string* RoomUser::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:packet.RoomUser.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RoomUser::release_name() {
  // @@protoc_insertion_point(field_release:packet.RoomUser.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RoomUser::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:packet.RoomUser.name)
}

// -------------------------------------------------------------------

// Room

// int64 id = 1;
inline void Room::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Room::id() const {
  // @@protoc_insertion_point(field_get:packet.Room.id)
  return id_;
}
inline void Room::set_id(::google::protobuf::int64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:packet.Room.id)
}

// string name = 2;
inline void Room::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Room::name() const {
  // @@protoc_insertion_point(field_get:packet.Room.name)
  return name_.GetNoArena();
}
inline void Room::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:packet.Room.name)
}
#if LANG_CXX11
inline void Room::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:packet.Room.name)
}
#endif
inline void Room::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:packet.Room.name)
}
inline void Room::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:packet.Room.name)
}
inline ::std::string* Room::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:packet.Room.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Room::release_name() {
  // @@protoc_insertion_point(field_release:packet.Room.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Room::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:packet.Room.name)
}

// int32 max_user_count = 3;
inline void Room::clear_max_user_count() {
  max_user_count_ = 0;
}
inline ::google::protobuf::int32 Room::max_user_count() const {
  // @@protoc_insertion_point(field_get:packet.Room.max_user_count)
  return max_user_count_;
}
inline void Room::set_max_user_count(::google::protobuf::int32 value) {
  
  max_user_count_ = value;
  // @@protoc_insertion_point(field_set:packet.Room.max_user_count)
}

// int64 master_user_network_id = 4;
inline void Room::clear_master_user_network_id() {
  master_user_network_id_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Room::master_user_network_id() const {
  // @@protoc_insertion_point(field_get:packet.Room.master_user_network_id)
  return master_user_network_id_;
}
inline void Room::set_master_user_network_id(::google::protobuf::int64 value) {
  
  master_user_network_id_ = value;
  // @@protoc_insertion_point(field_set:packet.Room.master_user_network_id)
}

// repeated .packet.RoomUser room_users = 5;
inline int Room::room_users_size() const {
  return room_users_.size();
}
inline void Room::clear_room_users() {
  room_users_.Clear();
}
inline ::packet::RoomUser* Room::mutable_room_users(int index) {
  // @@protoc_insertion_point(field_mutable:packet.Room.room_users)
  return room_users_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::packet::RoomUser >*
Room::mutable_room_users() {
  // @@protoc_insertion_point(field_mutable_list:packet.Room.room_users)
  return &room_users_;
}
inline const ::packet::RoomUser& Room::room_users(int index) const {
  // @@protoc_insertion_point(field_get:packet.Room.room_users)
  return room_users_.Get(index);
}
inline ::packet::RoomUser* Room::add_room_users() {
  // @@protoc_insertion_point(field_add:packet.Room.room_users)
  return room_users_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::packet::RoomUser >&
Room::room_users() const {
  // @@protoc_insertion_point(field_list:packet.Room.room_users)
  return room_users_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace packet

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_packet_5fdata_2eproto
