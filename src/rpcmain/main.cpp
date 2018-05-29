

#include <iostream>
#include <string>

#include <boost/thread.hpp>
#include <boost/bind.hpp>


#include "../lib/common/server_manager.hpp"

class rpcboostapp
{
public:
	rpcboostapp():
		signals_(rpcboost::common::server_manager::instance().get_io_service())
	{
		signals_.add(SIGINT);
		signals_.add(SIGQUIT);
		signals_.add(SIGTERM);
		signals_.add(SIGUSR1);
	}
	
	void run()
	{
		rpcboost::common::server_manager& m = rpcboost::common::server_manager::instance();

		
		// Run server in background thread.
		boost::thread t(boost::bind(&rpcboost::common::server_manager::run, &m));

		signals_.async_wait(boost::bind(&rpcboostapp::handle_signal, this, _1, _2));
		
		t.join();
	}
	
private:
	
	void handle_signal(const boost::system::error_code& e, int signal_number)
	{
		if(!e)
		{
			if( signal_number == SIGINT 
				|| signal_number == SIGQUIT 
				|| signal_number == SIGTERM)
			{
				rpcboost::common::server_manager::instance().stop_servers();
				return;
			}
			else if(signal_number == SIGUSR1)
			{
				signals_.async_wait(boost::bind(&rpcboostapp::handle_signal, this, _1, _2));
			}
			else
			{
			}	
		}
		else
		{
		}
	}

	boost::asio::signal_set signals_;
};


int main(int argc, char* argv[])
{

		

	rpcboostapp app;
	app.run();

	return 0;
}
