#include "server.hpp"

namespace rpcboost {
namespace common {
	
server::server(boost::asio::io_service& io_service):
	io_service_(io_service),
	status_(init)
{
	
}

server::~server()
{
	
}

void server::start()
{
	status_ = started;	
}

void server::stop()
{
	status_ = stopped;
}

} // namespace common
} // namespace rpcboost
