#include <boost/thread.hpp>

#include "server_manager.hpp"


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>


namespace rpcboost {
namespace common {



server_manager* server_manager::s_inst_ = NULL;

server_manager::server_manager():
	thread_pool_size_(10)
{
	BOOST_LOG_TRIVIAL(trace)<<"server_manager start";
}

server_manager::~server_manager()
{
}




void server_manager::add(const server_ptr& server)
{
	boost::unique_lock<boost::mutex> lock(mutex_);
	servers_.insert(server);
	lock.unlock();
	server->start();
}

void server_manager::run_io_service(int id)
{

	io_service_.run();
}

void server_manager::run()
{

	std::size_t num = thread_pool_size_;
	// Create a pool of threads to run all of the io_services.
	std::vector<boost::shared_ptr<boost::thread> > threads;
	for (std::size_t i = 0; i < num; ++i)
	{
		boost::shared_ptr<boost::thread> thread(new boost::thread(
			boost::bind(&server_manager::run_io_service, this, i)));

		threads.emplace_back(thread);
	}

	// Wait for all threads in the pool to exit.
	for (std::size_t i = 0; i < threads.size(); ++i)
	{
		threads[i]->join();
	}
}

void server_manager::stop_servers()
{
	boost::lock_guard<boost::mutex> lock(mutex_);
	
	for(std::set<server_ptr>::iterator it=servers_.begin(); it != servers_.end(); ++it)
	{
		(*it)->stop();	
	}

}

void server_manager::clear()
{
	boost::lock_guard<boost::mutex> lock(mutex_);
	servers_.clear();
}

void server_manager::set_work()
{
	boost::lock_guard<boost::mutex> lock(mutex_);
	work_.reset(new boost::asio::io_service::work(io_service_));
}

void server_manager::unset_work()
{
	boost::lock_guard<boost::mutex> lock(mutex_);
	work_.reset();
}

} // namespace common
} // namespace rpcboost
