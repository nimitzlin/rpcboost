#pragma once
#include <sstream>
#include <boost/array.hpp>

namespace rpcboost {
namespace rpc {
static const unsigned short k_rpc_data_size_bytes = 4;
	
class channel_request
{
public:
	typedef boost::array<char, k_rpc_data_size_bytes> size_buffer;
		
	channel_request():
		data_(std::ios_base::out|std::ios_base::in|std::ios_base::binary )
	{
		reset_buffer();
	}
		
	size_buffer&	size_buf() { return size_; }
	std::ostream&	data_wbuf() { return data_; }
	std::istream&	data_rbuf() { return data_; }
	
	std::size_t get_size();
	
	void reset()
	{	
		reset_buffer();
		
		data_.str("");
		data_.clear();
	}
		
private:
	void reset_buffer()
	{
		for(std::size_t i=0; i<size_.size(); ++i)
		{
			size_[i] = 0;	
		}	
	}
	
	size_buffer		size_;
	std::stringstream	data_;
};
	
} // namespace rpc
} // namespace rpcboost

