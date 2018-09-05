
#include <sstream>
#include <iostream>

#include "rpc_service.hpp"


namespace rpcboost{
namespace rpcserver{

rpc_service::rpc_service(rpcboost::rpc::rpc_channel* channel):
	rpcboost::rpc::service(channel),
	server_(""),
	client_stub_(channel)
{
	
}

rpc_service::~rpc_service()
{
}


void rpc_service::on_connection_unreg()
{		
	service::on_connection_unreg();
}

void rpc_service::SendServerMsg(::google::protobuf::RpcController* controller,
                       const ::rpcboost::test::InfoMsg* request,
                       ::rpcboost::test::Void* response,
                       ::google::protobuf::Closure* done)
{

}


} // namespace rpcserver
} // namespace rpcboost



