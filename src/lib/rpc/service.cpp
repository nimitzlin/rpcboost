
#include <glog/logging.h>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include "service.hpp"


namespace rpcboost {
namespace rpc {

service::service(rpcboost::rpc::rpc_channel* channel):
	channel_(channel)
{
	uuid_ = boost::uuids::random_generator()();
}

service::~service()
{
}

void service::on_connected()
{
	
}

void service::on_connection_unreg()
{
	//this->on_guard_destory();
}

} // namespace rpc
} // namespace rpcboost

