#include "connection_manager.hpp"

using boost::detail::spinlock;

namespace rpcboost {
namespace common {


connection_manager* connection_manager::s_inst_ = NULL;
	
connection_manager::connection_manager():
history_connection_num_(0),
sp_(BOOST_DETAIL_SPINLOCK_INIT)
{
}

connection_manager::~connection_manager()
{
	std::size_t n = connections_.size();
		
}

void connection_manager::register_connection(connection_ptr c)
{
	boost::lock_guard<spinlock> lock(sp_);

	connections_.insert(c);
	++history_connection_num_;
}

void connection_manager::unregister_connection(connection_ptr c)
{
	boost::lock_guard<spinlock> lock(sp_);
	connections_.erase(c);
}

bool connection_manager::has_connection(connection_ptr conn)
{
	boost::lock_guard<spinlock> lock(sp_);
	return connections_.find(conn) != connections_.end();
}

void connection_manager::stop_all()
{
	boost::lock_guard<spinlock> lock(sp_);
	for(std::set<connection_ptr>::iterator it = connections_.begin(); it != connections_.end(); ++it)
	{
		(*it)->close_socket();
	}
}

} // namespace common 
} // namespace rpcboost


