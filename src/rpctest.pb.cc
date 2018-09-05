// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rpctest.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "rpctest.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace rpcboost {
namespace test {

namespace {

const ::google::protobuf::Descriptor* Void_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Void_reflection_ = NULL;
const ::google::protobuf::Descriptor* InfoMsg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  InfoMsg_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* ServerService_descriptor_ = NULL;
const ::google::protobuf::ServiceDescriptor* ClientService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_rpctest_2eproto() {
  protobuf_AddDesc_rpctest_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "rpctest.proto");
  GOOGLE_CHECK(file != NULL);
  Void_descriptor_ = file->message_type(0);
  static const int Void_offsets_[1] = {
  };
  Void_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Void_descriptor_,
      Void::default_instance_,
      Void_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Void, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Void, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Void));
  InfoMsg_descriptor_ = file->message_type(1);
  static const int InfoMsg_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InfoMsg, msg_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InfoMsg, id_),
  };
  InfoMsg_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      InfoMsg_descriptor_,
      InfoMsg::default_instance_,
      InfoMsg_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InfoMsg, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InfoMsg, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(InfoMsg));
  ServerService_descriptor_ = file->service(0);
  ClientService_descriptor_ = file->service(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_rpctest_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Void_descriptor_, &Void::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    InfoMsg_descriptor_, &InfoMsg::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_rpctest_2eproto() {
  delete Void::default_instance_;
  delete Void_reflection_;
  delete InfoMsg::default_instance_;
  delete InfoMsg_reflection_;
}

void protobuf_AddDesc_rpctest_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rrpctest.proto\022\rrpcboost.test\"\006\n\004Void\"\""
    "\n\007InfoMsg\022\013\n\003msg\030\001 \002(\014\022\n\n\002id\030\002 \002(\0052M\n\rSe"
    "rverService\022<\n\rSendServerMsg\022\026.rpcboost."
    "test.InfoMsg\032\023.rpcboost.test.Void2M\n\rCli"
    "entService\022<\n\rSendClientMsg\022\026.rpcboost.t"
    "est.InfoMsg\032\023.rpcboost.test.VoidB\006\200\001\001\220\001\001", 240);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "rpctest.proto", &protobuf_RegisterTypes);
  Void::default_instance_ = new Void();
  InfoMsg::default_instance_ = new InfoMsg();
  Void::default_instance_->InitAsDefaultInstance();
  InfoMsg::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_rpctest_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_rpctest_2eproto {
  StaticDescriptorInitializer_rpctest_2eproto() {
    protobuf_AddDesc_rpctest_2eproto();
  }
} static_descriptor_initializer_rpctest_2eproto_;

// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

Void::Void()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:rpcboost.test.Void)
}

void Void::InitAsDefaultInstance() {
}

Void::Void(const Void& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:rpcboost.test.Void)
}

void Void::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Void::~Void() {
  // @@protoc_insertion_point(destructor:rpcboost.test.Void)
  SharedDtor();
}

void Void::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Void::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Void::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Void_descriptor_;
}

const Void& Void::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpctest_2eproto();
  return *default_instance_;
}

Void* Void::default_instance_ = NULL;

Void* Void::New() const {
  return new Void;
}

void Void::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Void::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:rpcboost.test.Void)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:rpcboost.test.Void)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:rpcboost.test.Void)
  return false;
#undef DO_
}

void Void::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:rpcboost.test.Void)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:rpcboost.test.Void)
}

::google::protobuf::uint8* Void::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:rpcboost.test.Void)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rpcboost.test.Void)
  return target;
}

int Void::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Void::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Void* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Void*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Void::MergeFrom(const Void& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Void::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Void::CopyFrom(const Void& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Void::IsInitialized() const {

  return true;
}

void Void::Swap(Void* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Void::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Void_descriptor_;
  metadata.reflection = Void_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int InfoMsg::kMsgFieldNumber;
const int InfoMsg::kIdFieldNumber;
#endif  // !_MSC_VER

InfoMsg::InfoMsg()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:rpcboost.test.InfoMsg)
}

void InfoMsg::InitAsDefaultInstance() {
}

InfoMsg::InfoMsg(const InfoMsg& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:rpcboost.test.InfoMsg)
}

void InfoMsg::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  id_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

InfoMsg::~InfoMsg() {
  // @@protoc_insertion_point(destructor:rpcboost.test.InfoMsg)
  SharedDtor();
}

void InfoMsg::SharedDtor() {
  if (msg_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete msg_;
  }
  if (this != default_instance_) {
  }
}

void InfoMsg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* InfoMsg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return InfoMsg_descriptor_;
}

const InfoMsg& InfoMsg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rpctest_2eproto();
  return *default_instance_;
}

InfoMsg* InfoMsg::default_instance_ = NULL;

InfoMsg* InfoMsg::New() const {
  return new InfoMsg;
}

void InfoMsg::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_msg()) {
      if (msg_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        msg_->clear();
      }
    }
    id_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool InfoMsg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:rpcboost.test.InfoMsg)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bytes msg = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_msg()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_id;
        break;
      }

      // required int32 id = 2;
      case 2: {
        if (tag == 16) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:rpcboost.test.InfoMsg)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:rpcboost.test.InfoMsg)
  return false;
#undef DO_
}

void InfoMsg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:rpcboost.test.InfoMsg)
  // required bytes msg = 1;
  if (has_msg()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->msg(), output);
  }

  // required int32 id = 2;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:rpcboost.test.InfoMsg)
}

::google::protobuf::uint8* InfoMsg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:rpcboost.test.InfoMsg)
  // required bytes msg = 1;
  if (has_msg()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->msg(), target);
  }

  // required int32 id = 2;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rpcboost.test.InfoMsg)
  return target;
}

int InfoMsg::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required bytes msg = 1;
    if (has_msg()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->msg());
    }

    // required int32 id = 2;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void InfoMsg::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const InfoMsg* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const InfoMsg*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void InfoMsg::MergeFrom(const InfoMsg& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_msg()) {
      set_msg(from.msg());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void InfoMsg::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void InfoMsg::CopyFrom(const InfoMsg& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool InfoMsg::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void InfoMsg::Swap(InfoMsg* other) {
  if (other != this) {
    std::swap(msg_, other->msg_);
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata InfoMsg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = InfoMsg_descriptor_;
  metadata.reflection = InfoMsg_reflection_;
  return metadata;
}


// ===================================================================

ServerService::~ServerService() {}

const ::google::protobuf::ServiceDescriptor* ServerService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ServerService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* ServerService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return ServerService_descriptor_;
}

void ServerService::SendServerMsg(::google::protobuf::RpcController* controller,
                         const ::rpcboost::test::InfoMsg*,
                         ::rpcboost::test::Void*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method SendServerMsg() not implemented.");
  done->Run();
}

void ServerService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), ServerService_descriptor_);
  switch(method->index()) {
    case 0:
      SendServerMsg(controller,
             ::google::protobuf::down_cast<const ::rpcboost::test::InfoMsg*>(request),
             ::google::protobuf::down_cast< ::rpcboost::test::Void*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& ServerService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::rpcboost::test::InfoMsg::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& ServerService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::rpcboost::test::Void::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

ServerService_Stub::ServerService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
ServerService_Stub::ServerService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
ServerService_Stub::~ServerService_Stub() {
  if (owns_channel_) delete channel_;
}

void ServerService_Stub::SendServerMsg(::google::protobuf::RpcController* controller,
                              const ::rpcboost::test::InfoMsg* request,
                              ::rpcboost::test::Void* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
// ===================================================================

ClientService::~ClientService() {}

const ::google::protobuf::ServiceDescriptor* ClientService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ClientService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* ClientService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return ClientService_descriptor_;
}

void ClientService::SendClientMsg(::google::protobuf::RpcController* controller,
                         const ::rpcboost::test::InfoMsg*,
                         ::rpcboost::test::Void*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method SendClientMsg() not implemented.");
  done->Run();
}

void ClientService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), ClientService_descriptor_);
  switch(method->index()) {
    case 0:
      SendClientMsg(controller,
             ::google::protobuf::down_cast<const ::rpcboost::test::InfoMsg*>(request),
             ::google::protobuf::down_cast< ::rpcboost::test::Void*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& ClientService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::rpcboost::test::InfoMsg::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& ClientService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::rpcboost::test::Void::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

ClientService_Stub::ClientService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
ClientService_Stub::ClientService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
ClientService_Stub::~ClientService_Stub() {
  if (owns_channel_) delete channel_;
}

void ClientService_Stub::SendClientMsg(::google::protobuf::RpcController* controller,
                              const ::rpcboost::test::InfoMsg* request,
                              ::rpcboost::test::Void* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)

}  // namespace test
}  // namespace rpcboost

// @@protoc_insertion_point(global_scope)
