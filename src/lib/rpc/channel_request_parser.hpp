#pragma once
#include <boost/logic/tribool.hpp>
#include <boost/tuple/tuple.hpp>
#include "channel_request.hpp"

namespace rpcboost {
namespace rpc {
	
class channel_request_parser
{
public:
	
	static const unsigned int RECV_LIMIT = 0xFFFFFF;
	
	enum parse_state
	{
		state_size = 0,
		state_data,
	};
	
	channel_request_parser();
	
	boost::tuple<boost::tribool, std::size_t> parse(channel_request& request, const void* data, const std::size_t size);
	
	void reset();
	
	parse_state get_state() { return state_; }
	
	std::size_t get_need_bytes() { return need_bytes_; }
		
	void set_recv_limit(const unsigned int size)
	{
		recv_limit_ = size;
	}
	
private:
	parse_state	state_;
	std::size_t	need_bytes_;
	std::size_t	recv_limit_;
};
	
} // namespace rpc
} // namespace rpcboost

