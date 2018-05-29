#pragma once
#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace rpcboost {
namespace common {


class server
	:
  	public boost::enable_shared_from_this<server>,
  	private boost::noncopyable
{
public:

	enum server_status {
		init = 0,
		started,
		stopped,	
	};
	
	server(boost::asio::io_service& io_service);
	virtual ~server();
	virtual void start();
	virtual void stop();

	server_status get_status() const { return status_; }
	bool is_stopped() const { return status_ == stopped; }

protected:
	boost::asio::io_service&	io_service_;
	server_status			status_;
};

typedef boost::shared_ptr<server> server_ptr;

} // namespace common
} // namespace rpcboost
