#pragma once
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <sstream>
#include <vector>
#include <list>
#include "stdef.hpp"
#include "connection.hpp"
#include "../rpc/rpc_channel.hpp"

namespace rpcboost {
namespace common {

typedef std::vector<boost::asio::const_buffer> async_write_buffers;

class normal_listen_connection
	:
	public rpcboost::common::connection
	
{
public:

	normal_listen_connection(boost::asio::io_service& io_service);
	virtual ~normal_listen_connection();
	
	std::size_t get_buffer_size() { return buffer_.size(); }
	void set_buffer_size(std::size_t size) { std::vector<char> tmp(size); buffer_.swap(tmp); }

	void set_send_limit(const unsigned int size) { send_limit_ = size; }
	unsigned int get_send_limit() { return send_limit_; }
	unsigned int get_queue_size() { return data_queue_size_; }
	
	virtual void start_work();
	virtual void close_socket();
	virtual void async_write_data(rpcboost::common::write_buf_ptr data);
	virtual boost::asio::ip::tcp::endpoint get_remote_endpoint();
	boost::asio::ip::tcp::socket& socket() { return socket_; }

	virtual void disconnect();
protected:
	virtual void cleanup() = 0;
	virtual void handle_close_socket();

	virtual void handle_connected_read(const boost::system::error_code& e, std::size_t bytes_transferred) = 0;
	virtual void handle_async_write_data(const boost::system::error_code& e);

	boost::asio::ip::tcp::socket			socket_;

	std::vector<char> 				buffer_;
	unsigned int 					data_queue_size_;
	bool						sending_data_;
	unsigned int					send_limit_;
	write_buffers_ptr				data_queue_;
	write_buffers_ptr				send_queue_;
};

} // namespace common
} // namespace rpcboost

