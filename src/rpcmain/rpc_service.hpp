
#pragma once

#include "../rpctest.pb.h"

#include "../lib/rpc/service.hpp"
#include "../lib/rpc/rpc_channel.hpp"
#include "../lib/utils/callback_helper.hpp"

namespace rpcboost{
namespace rpcserver{

class rpc_service : 
	public rpcboost::rpc::service,
	public rpcboost::test::ServerService
{
public:
	rpc_service(rpcboost::rpc::rpc_channel* channel);
	virtual ~rpc_service();
	virtual void on_connection_unreg();

	virtual void SendServerMsg(::google::protobuf::RpcController* controller,
                       const ::rpcboost::test::InfoMsg* request,
                       ::rpcboost::test::Void* response,
                       ::google::protobuf::Closure* done);

private:

	std::string			server_;
	rpcboost::test::ClientService_Stub	client_stub_;
};

typedef boost::shared_ptr<rpcboost::rpcserver::rpc_service> rpc_service_ptr;

} // namespace rpcserver
} // namespace rpcboost

