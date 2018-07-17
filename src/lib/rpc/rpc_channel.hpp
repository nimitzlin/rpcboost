#pragma once
#include <boost/logic/tribool.hpp>
#include <google/protobuf/service.h>
#include "../common/connection.hpp"
#include "../common/common.hpp"
#include "channel_request.hpp"
#include "channel_request_parser.hpp"

namespace rpcboost {
namespace rpc {

typedef unsigned short method_index_type;

class rpc_channel : public ::google::protobuf::RpcChannel
{
public:
	rpc_channel(rpcboost::common::connection* conn);
	virtual ~rpc_channel();
	
	virtual void CallMethod(const ::google::protobuf::MethodDescriptor* method,
				::google::protobuf::RpcController* controller,
				const ::google::protobuf::Message* request,
				::google::protobuf::Message* response,
				::google::protobuf::Closure* done);
	
	void set_service(::google::protobuf::Service* service) { service_ = service; };
	boost::tribool input_data(const void* data, const std::size_t size);
	boost::asio::ip::tcp::endpoint get_remote_endpoint();
	strand_ptr get_strand() { return conn_->get_strand(); }

	void set_recv_limit(const std::size_t size)
	{
		request_parser_.set_recv_limit(size);
	}

	void disconnect() { conn_->disconnect(); }
	unsigned int get_queue_size() { return conn_->get_queue_size(); }
private:
	
	bool on_request();
	
	rpcboost::common::connection*		conn_;
	::google::protobuf::Service*	service_;
	channel_request			request_;
	channel_request_parser		request_parser_;
};

} // namespace rpc
} // namespace rpcboost
