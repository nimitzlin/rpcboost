
#pragma once
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <sstream>

#ifdef TCP_KEEPIDLE
#define USE_KEEPALIVE
#endif

typedef boost::shared_ptr<boost::asio::io_service::strand>	strand_ptr;


namespace rpcboost {
namespace common {

typedef boost::shared_ptr<boost::asio::streambuf> 		write_buf_ptr;
typedef std::vector<write_buf_ptr>				write_buffers;
typedef boost::shared_ptr<write_buffers> 		write_buffers_ptr;

class connection
	:
	public boost::enable_shared_from_this<connection>,
	private boost::noncopyable
	
{
public:
	
#ifdef USE_KEEPALIVE
	typedef boost::asio::detail::socket_option::integer<SOL_TCP, TCP_KEEPIDLE> keepidle;
	typedef boost::asio::detail::socket_option::integer<SOL_TCP, TCP_KEEPINTVL> keepintvl;
	typedef boost::asio::detail::socket_option::integer<SOL_TCP, TCP_KEEPCNT> keepcnt;
#endif

	explicit connection(boost::asio::io_service& io_service);
	virtual ~connection();
	
	/// Start the first asynchronous operation for the connection.

	void start();
	void stop();
	void unreg();
	strand_ptr get_strand() { return strand_; }
	
	//virtual void set_options() = 0;
	virtual void start_work() = 0;
	virtual void close_socket() = 0;
	virtual void async_write_data(rpcboost::common::write_buf_ptr data) = 0;
	virtual boost::asio::ip::tcp::endpoint get_remote_endpoint() = 0;

	virtual void disconnect() = 0;
	bool is_alive();

	virtual unsigned int get_queue_size() { return 0; }

protected:
	/// Strand to ensure the connection's handlers are not called concurrently.
	strand_ptr 				strand_;
};

typedef boost::shared_ptr<connection> connection_ptr;

#define CN_CALLBACK(CLASS, FUN, ...) \
	strand_->wrap(boost::bind(&CLASS::FUN, boost::static_pointer_cast<CLASS>(shared_from_this()), ##__VA_ARGS__))

#define CN_POST(CLASS, FUN, ...) \
	strand_->post(boost::bind(&CLASS::FUN, boost::static_pointer_cast<CLASS>(shared_from_this()), ##__VA_ARGS__))

} // namespace const
} // namespace rpcboost

