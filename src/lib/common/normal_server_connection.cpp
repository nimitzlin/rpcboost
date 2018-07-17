
#include "normal_server_connection.hpp"
#include "connection_manager.hpp"

namespace gt {
namespace rpcboost {
	
normal_listen_connection::normal_listen_connection(boost::asio::io_service& io_service):
	gt::common::connection(io_service),
	socket_(io_service),
	buffer_(128),
	data_queue_size_(0),
	sending_data_(false),
	send_limit_(0),
	data_queue_(new write_buffers),
	send_queue_(new write_buffers)
{
}

normal_listen_connection::~normal_listen_connection()
{
}


void normal_listen_connection::close_socket()
{
	CN_POST(normal_listen_connection, handle_close_socket);
}

void normal_listen_connection::disconnect()
{
	this->close_socket();
}

void normal_listen_connection::handle_close_socket()
{
	if(socket_.lowest_layer().is_open())
	{
		boost::system::error_code ec;
		socket_.lowest_layer().shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
		socket_.lowest_layer().close(ec);
	}
}

boost::asio::ip::tcp::endpoint normal_listen_connection::get_remote_endpoint()
{
	boost::system::error_code ec;
	return socket_.lowest_layer().remote_endpoint(ec);
}

void normal_listen_connection::start_work()
{
	socket_.async_read_some(
		boost::asio::buffer(buffer_),
		CN_CALLBACK(normal_listen_connection, handle_connected_read, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)
	);
}

void normal_listen_connection::handle_async_write_data(const boost::system::error_code& e)
{
	CHECK(sending_data_);
	
	send_queue_->clear();
	std::size_t sz = data_queue_->size();
	if (sz > 0)
	{
		data_queue_.swap(send_queue_);
		if (sz > 1)
		{
			async_write_buffers buffs;
			buffs.reserve(sz);

			for (write_buffers::iterator it = send_queue_->begin(); it != send_queue_->end(); ++it)
			{
				buffs.emplace_back(static_cast<boost::asio::const_buffer>((*it)->data()));
				data_queue_size_ -= ((*it)->size());		
			}

			boost::asio::async_write(
				socket_,
				buffs, 
				CN_CALLBACK(
					normal_listen_connection,
					handle_async_write_data,
					boost::asio::placeholders::error
				)
			);
		}
		else
		{
			write_buf_ptr &data = send_queue_->operator[](0);
			data_queue_size_ -= data->size();
			boost::asio::async_write(
					socket_,
					*data,
					CN_CALLBACK(
						normal_listen_connection,
						handle_async_write_data,
						boost::asio::placeholders::error
					)
			);
		}
	}
	else
	{
		sending_data_ = false;
	}
}

void normal_listen_connection::async_write_data(gt::common::write_buf_ptr data)
{

	if(send_limit_ > 0 && data_queue_size_ > send_limit_)
	{
		//LOG(ERROR) << __FUNCTION__ << " out of limit " << send_limit_ << " : " << data_queue_size_;
		return;
	}

	if(sending_data_)
	{
		data_queue_->emplace_back(data);
		data_queue_size_ += (unsigned int)(data->size());
	}
	else
	{
		sending_data_ = true;
		send_queue_->emplace_back(data);
		boost::asio::async_write(
			socket_,
			*data, 
			CN_CALLBACK(
				normal_listen_connection,
				handle_async_write_data,
				boost::asio::placeholders::error
			)
		);
	}
}

} // namespace common
} // namespace rpcboost

