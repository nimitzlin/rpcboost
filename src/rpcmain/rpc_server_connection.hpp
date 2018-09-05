
#pragma once
#include <boost/scoped_ptr.hpp>
#include "../lib/common/rpc_listen_connection.hpp"
#include "rpc_service.hpp"

namespace rpcboost{
namespace rpcserver{

class rpc_server_connection : public rpcboost::common::rpc_listen_connection
{
public:
	explicit rpc_server_connection(boost::asio::io_service& io_service);
	virtual ~rpc_server_connection();
	
protected:
	virtual void cleanup();

private:

	boost::scoped_ptr<rpcboost::rpcserver::rpc_service>		service_;
};

typedef boost::shared_ptr<rpc_server_connection> rpc_server_connection_ptr;

} // namespace rpcserver
} // namespace rpcboost

