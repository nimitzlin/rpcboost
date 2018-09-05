
#pragma once

#include "normal_listen_connection.hpp"


namespace rpcboost {
namespace common {

class rpc_listen_connection
	:
	public rpcboost::common::normal_listen_connection
	
{
public:
	rpc_listen_connection(boost::asio::io_service& io_service);
	void set_recv_limit(const unsigned int size) { channel_->set_recv_limit(size); }

protected:
	
	virtual void handle_connected_read(const boost::system::error_code& e, std::size_t bytes_transferred);
	virtual void handle_read_rpc(const boost::system::error_code& e, std::size_t bytes_transferred);

	boost::scoped_ptr<rpcboost::rpc::rpc_channel>		channel_;

};

} // namespace common
} // namespace rpcboost

