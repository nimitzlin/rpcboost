
#include "rpc_server_connection.hpp"

namespace rpcboost {
namespace rpcserver {

rpc_server_connection::rpc_server_connection(boost::asio::io_service& io_service):
	rpcboost::common::rpc_listen_connection(io_service),
	service_(new rpcboost::rpcserver::rpc_service(channel_.get()))
{
	channel_->set_service(service_.get());
}

rpc_server_connection::~rpc_server_connection()
{
}

void rpc_server_connection::cleanup()
{
	service_->on_connection_unreg();
	//this->unreg();
}

} // namespace rpcserver
} // namespace rpcboost

