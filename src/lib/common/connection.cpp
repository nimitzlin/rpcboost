
#include "connection.hpp"
#include "connection_manager.hpp"

namespace  rpcboost{
namespace common {
	
connection::connection(boost::asio::io_service& io_service):
	strand_(new boost::asio::io_service::strand(io_service))
{
}

connection::~connection()
{
}

void connection::start()
{
	connection_manager::instance().register_connection(shared_from_this());
	this->start_work();
}

void connection::stop()
{
	connection_manager::instance().unregister_connection(shared_from_this());
	this->close_socket();
}

void connection::unreg()
{
	connection_manager::instance().unregister_connection(shared_from_this());
}

bool connection::is_alive()
{
	return connection_manager::instance().has_connection(shared_from_this());
}

} // namespace common 
} // namespace rpcboost

