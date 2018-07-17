#include "channel_request_parser.hpp"

namespace rpcboost {
namespace rpc {

channel_request_parser::channel_request_parser():
	state_(state_size),
	need_bytes_(k_rpc_data_size_bytes),
	recv_limit_(RECV_LIMIT)
{
	
}

void channel_request_parser::reset()
{
	state_ = state_size;
	need_bytes_ = k_rpc_data_size_bytes;
}

boost::tuple<boost::tribool, std::size_t> channel_request_parser::parse(channel_request& request, const void* data, const std::size_t size)
{
	
	char* pdata = static_cast<char*>(const_cast<void*>(data));
	boost::tribool result;

	switch(state_)
	{
	case state_size:
		{
			if(need_bytes_ > size)
			{
				std::size_t insert_size = size;
				std::size_t buf_size = request.size_buf().size();
				for(std::size_t i= buf_size - need_bytes_; i< buf_size - need_bytes_ + insert_size; ++i)
				{
					request.size_buf()[i] = *pdata;
					++pdata;
				}
				
				need_bytes_ -= insert_size;
				
				result = boost::indeterminate;
				return boost::make_tuple(result, insert_size);
			}
			else
			{
				std::size_t insert_size = need_bytes_;
				std::size_t buf_size = request.size_buf().size();
				for(std::size_t i = buf_size - need_bytes_; i<buf_size; ++i)
				{
					request.size_buf()[i] = *pdata;
					++pdata;
				}
				
				state_ = state_data;
				need_bytes_ = request.get_size();
				
				if(need_bytes_ == 0 || need_bytes_ > recv_limit_)
				{
					result = false;
					return boost::make_tuple(result, insert_size);
				}
				
				result = boost::indeterminate;
				return boost::make_tuple(result, insert_size);
			}
			break;
		}
		
	case state_data:
		{
			if(need_bytes_ > size)
			{
				std::size_t insert_size = size;

				request.data_wbuf().write(pdata, insert_size);
				
				need_bytes_ -= insert_size;
				
				result = boost::indeterminate;
				return boost::make_tuple(result, insert_size);
			}
			else //if(need_bytes_ <= size)
			{
				std::size_t insert_size = need_bytes_;
					
				request.data_wbuf().write(pdata, insert_size);
				
				int req_size = request.get_size();
				
				reset();
				result = true;
				return boost::make_tuple(result, insert_size);
			}
			break;
		}
	
	default:
		{
			result = false;
			return boost::make_tuple(result, 0);
		}
	}
}

} // namespace rpc
} // namespace rpcboost

