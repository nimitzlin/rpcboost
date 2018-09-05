
#pragma once

#include <boost/asio.hpp>

#include "rpc_server_connection.hpp"
#include "../lib/common/server.hpp"
#include "../lib/common/server_manager.hpp"

namespace rpcboost{
namespace rpcserver{

// translate data with game servers

class rpc_server : public rpcboost::common::server
{
public:
	explicit rpc_server();
	virtual void start();
	virtual void stop();

private:
	void handle_start_server();
	void handle_accept(const boost::system::error_code& e);

	boost::asio::ip::tcp::acceptor acceptor_;
	rpc_server_connection_ptr new_connection_;
};

typedef boost::shared_ptr<rpc_server> rpc_server_ptr;

}	// rpcserver
}	// rpcboost

