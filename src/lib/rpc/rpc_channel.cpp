#include <glog/logging.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <ostream>
#include "rpc_channel.hpp"

namespace rpcboost {
namespace rpc {


rpc_channel::rpc_channel(rpcboost::common::connection* conn):
	conn_(conn),
	service_(NULL)
{
	
}

rpc_channel::~rpc_channel()
{
	
}

boost::asio::ip::tcp::endpoint rpc_channel::get_remote_endpoint()
{
	return conn_->get_remote_endpoint();
}

boost::tribool rpc_channel::input_data(const void* data, const std::size_t size)
{
	
	char* pdata = static_cast<char*>(const_cast<void*>(data));
	std::size_t input_size = size;
	std::size_t total_consum_size = 0;	
		
	while(size >total_consum_size)
	{
		boost::tribool 	result;
		std::size_t	consum_size;
			
		boost::tie(result, consum_size) = request_parser_.parse(request_, static_cast<const void*>(pdata), input_size);
		
		total_consum_size += consum_size;
		pdata += consum_size;
		input_size -= consum_size;
		
		if(result)
		{	
			bool ok = on_request();
			
			request_.reset();
			
			if(!ok)
			{
				return false;	
			}
			continue;
		}
		else if(!result)	// error in parse()
		{
			return false;
		}
		else
		{
			continue;	
		}
	}
		
	return boost::indeterminate;;
}

bool rpc_channel::on_request()
{
	if(request_.get_size() < sizeof(method_index_type))
	{
		LOG(ERROR) << "Got error request size: " << request_.get_size();
		conn_->close_socket();
		return false;
	}
	
	method_index_type index; // = *(reinterpret_cast< method_index_type* >( const_cast< char* >( request_.data_buf().data() ) ) );
	
	request_.data_rbuf().read(reinterpret_cast<char*>(&index), sizeof(index));
	
	if(index >= service_->GetDescriptor()->method_count())
	{
		LOG(ERROR) << "Got error method index: " << index;
		conn_->close_socket();
		return false;
	}
	
	const ::google::protobuf::MethodDescriptor* method = service_->GetDescriptor()->method(index);
	boost::scoped_ptr<google::protobuf::Message> request(service_->GetRequestPrototype(method).New());
	
	if(!request->ParseFromIstream(&request_.data_rbuf()))
	{
		LOG(ERROR) << "request->ParseFromIstream() failed. size: " << request_.get_size() << " method index: " << index << " -> " << method->full_name() << " (" << request->GetDescriptor()->full_name() << ")" ;
		conn_->close_socket();
		return false;	
	}
	
	
	service_->CallMethod(method, NULL, request.get(), NULL, NULL);
	
	return true;	
}

void rpc_channel::CallMethod(const ::google::protobuf::MethodDescriptor* method,
				::google::protobuf::RpcController* controller,
				const ::google::protobuf::Message* request,
				::google::protobuf::Message* response,
				::google::protobuf::Closure* done)
{
	std::ostringstream osdata;
	
	method_index_type index = method->index();
	CHECK(index < 65535);
	
	osdata.write(reinterpret_cast<const char*>(&index), sizeof(index));
	
	if(!request->SerializeToOstream(&osdata))
	{
		LOG(ERROR) << "rpc_channel::CallMethod() failed to SerializeToOstream." ;
		conn_->close_socket();
		return;	
	}
	
	std::string data_string = osdata.str();
		
	unsigned int total_len = data_string.size();

	BOOST_STATIC_ASSERT(sizeof(total_len) == 4);

	rpcboost::common::write_buf_ptr buf(new boost::asio::streambuf());
	std::ostream os(buf.get());
	
	
	os.write(reinterpret_cast<const char*>(&total_len), sizeof(total_len));
	os.write(data_string.data(), data_string.size());
	
	conn_->async_write_data(buf);
}

} // namespace rpc
} // namespace rpcboost

