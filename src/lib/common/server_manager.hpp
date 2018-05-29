#pragma once
#include <set>
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "server.hpp"

namespace rpcboost {
namespace common {

typedef boost::shared_ptr<boost::asio::io_service::work> work_ptr;
/// Manages open connections so that they may be cleanly stopped when the server
/// needs to shut down.
class server_manager
	: private boost::noncopyable
{
public:
	static server_manager& instance() { return *s_inst_; }
	static void init() { s_inst_ = new server_manager(); }
	static void fini() { delete s_inst_; }
	
	void set_thread_num(std::size_t num) { thread_pool_size_ = num; }
	std::size_t get_thread_num() const { return thread_pool_size_; }
		
	boost::asio::io_service& get_io_service() { return io_service_; }

	void add(const server_ptr& server);
	void run();
	void run_io_service(int id);
	
	void stop_servers();
	void set_work();
	void unset_work();
	void clear();
private:
	
	static server_manager* s_inst_;
	
	server_manager();
	virtual ~server_manager();
	
	/// The io_service used to perform asynchronous operations.
	boost::asio::io_service io_service_;	
	
	/// The number of threads that will call io_service::run().
	std::size_t 		thread_pool_size_;

	boost::mutex 		mutex_;
	/// The managed connections.
	std::set<server_ptr> 	servers_;
		
	work_ptr		work_;
};

} // namespace common
} // namespace rpcboost

