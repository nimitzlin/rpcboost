
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>

#include "rpcserver.hpp"

static std::string rpc_ip = "0.0.0.0";
static int rpc_port = 9898;

namespace rpcboost{
namespace rpcserver{
	
rpc_server::rpc_server():
	server(rpcboost::common::server_manager::instance().get_io_service()),
	acceptor_(io_service_),
	new_connection_(new rpc_server_connection(io_service_))
{
}

void rpc_server::handle_start_server()
{
	boost::asio::ip::tcp::resolver resolver(io_service_);
	boost::asio::ip::tcp::resolver::query query(rpc_ip, boost::lexical_cast<std::string>(rpc_port));
	boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve(query);

	acceptor_.open(endpoint.protocol());
	acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
	acceptor_.set_option(boost::asio::ip::tcp::socket::keep_alive(true));
	acceptor_.set_option(boost::asio::ip::tcp::no_delay(true));
#ifdef USE_KEEPALIVE
	acceptor_.set_option(rpcboost::common::connection::keepidle(60));
	acceptor_.set_option(rpcboost::common::connection::keepintvl(60));
	acceptor_.set_option(rpcboost::common::connection::keepcnt(3));
#endif
	acceptor_.bind(endpoint);
	acceptor_.listen();

	acceptor_.async_accept(
			new_connection_->socket(),
			boost::bind(
				&rpc_server::handle_accept,
				boost::static_pointer_cast<rpc_server>(shared_from_this()),
				boost::asio::placeholders::error
			)
	);
}

void rpc_server::handle_accept(const boost::system::error_code& e)
{
	if (!e)
	{
		new_connection_->start();
		new_connection_.reset(new rpc_server_connection(io_service_));
		new_connection_->set_buffer_size(64*1024);
		acceptor_.async_accept(
				new_connection_->socket(), 
				boost::bind(
					&rpc_server::handle_accept,
					boost::static_pointer_cast<rpc_server>(shared_from_this()),
					boost::asio::placeholders::error
				)
		);
	}
}

void rpc_server::start()
{
	rpcboost::common::server::start();
	io_service_.post(boost::bind(&rpc_server::handle_start_server, boost::static_pointer_cast<rpc_server>(shared_from_this())));
}

void rpc_server::stop()
{
	rpcboost::common::server::stop();
	acceptor_.close();
}

} // namespace rpcserver
} // namespace rpc


