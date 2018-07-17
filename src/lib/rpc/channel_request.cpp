#include "channel_request.hpp"


namespace rpcboost {
namespace rpc {
	
std::size_t channel_request::get_size()
{
	
	unsigned int s = *(reinterpret_cast<unsigned int*>(size_.data()));
	return s;
}
	


} // namespace rpc
} // namespace rpcboost

