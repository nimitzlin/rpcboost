
#include <glog/logging.h>
#include "rpc_listen_connection.hpp"

namespace rpcboost {
namespace common {
	
rpc_listen_connection::rpc_listen_connection(boost::asio::io_service& io_service):
	rpcboost::common::normal_listen_connection(io_service),
	channel_(new rpcboost::rpc::rpc_channel(this))
{
	
}


void rpc_listen_connection::handle_connected_read(const boost::system::error_code& e, std::size_t bytes_transferred)
{
	this->handle_read_rpc(e, bytes_transferred);
}

void rpc_listen_connection::handle_read_rpc(const boost::system::error_code& e, std::size_t bytes_transferred)
{
	DLOG(INFO) << __FUNCTION__ << " " << this << " " << e << " " << bytes_transferred;
	
	if (!e)
	{
		boost::tribool result = channel_->input_data(buffer_.data(), bytes_transferred);
			
		DLOG(INFO) << "rpc_listen_connection::handle_read_rpc(): input_data ->" << result;
		
		if(result)
		{
			//should never happen!
			CHECK(false);
		}
		else if(!result)
		{
			LOG(ERROR) << "failed in channel_.input_data()" ;
			this->cleanup();
		}
		else
		{
			socket_.async_read_some(
				boost::asio::buffer(buffer_),
				CN_CALLBACK(rpc_listen_connection, handle_read_rpc, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)
			);			
		}

	}
	else
	{
		this->cleanup();
	}	
}

} // namespace common
} // namespace rpcboost

