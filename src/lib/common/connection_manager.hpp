
#pragma once
#include <boost/thread.hpp>
#include <boost/smart_ptr/detail/spinlock.hpp>
#include <set>
#include <boost/noncopyable.hpp>
#include "connection.hpp"

using boost::detail::spinlock;

namespace rpcboost {
namespace common {

class connection_manager
	: private boost::noncopyable
{
public:
	static connection_manager& instance() {
		if(!s_inst_){
			init();
	   }
		return *s_inst_; }
	static void init() { s_inst_ = new connection_manager(); }
	static void fini() { delete s_inst_; }
	

	void register_connection(connection_ptr c);
	
	void unregister_connection(connection_ptr c);
	
	void stop_all();
	
	std::size_t get_connection_count() const { return connections_.size(); }

	bool has_connection(connection_ptr conn);

private:
	static connection_manager* s_inst_;
	
	connection_manager();
	virtual ~connection_manager();
	std::set<connection_ptr> connections_;
	std::size_t	history_connection_num_;
	mutable spinlock sp_;


};

} // namespace rpcboost
} // namespace gt

