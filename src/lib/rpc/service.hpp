#pragma once
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/noncopyable.hpp>
#include "../utils/callback_helper.hpp"
#include "rpc_channel.hpp"

namespace rpcboost {
namespace rpc {

class service
	:
	private boost::noncopyable,
	public rpcboost::utils::destory_guard
{
public:
	service(rpcboost::rpc::rpc_channel* channel);
	virtual ~service();

	virtual void on_connection_unreg();
	virtual void on_connected();

	boost::uuids::uuid uuid() const { return uuid_; }

	template<typename AT_CLASS, typename FUNC>
	void post(FUNC func)
	{
		channel_->get_strand()->post(make_safe_callback(channel_->get_strand(), 
			boost::bind(func, static_cast<AT_CLASS*>(this))));
	}

	template<typename AT_CLASS, typename FUNC, typename CALLBACK_FUNC >
	void callback(FUNC func, CALLBACK_FUNC callback_func)
	{
		channel_->get_strand()->post(make_safe_callback(channel_->get_strand(), 
			boost::bind(callback_func, boost::bind(func, static_cast<AT_CLASS*>(this)))));
	}

protected:
	rpcboost::rpc::rpc_channel*		channel_;

private:
	boost::uuids::uuid		uuid_;
};

#define SV_CALLBACK(CLASS, FUN, ...) \
	channel_->get_strand()->wrap(make_safe_callback(channel_->get_strand(), boost::bind(&CLASS::FUN, this, ##__VA_ARGS__)))

#define SV_POST(CLASS, FUN, ...) \
	channel_->get_strand()->post(make_safe_callback(channel_->get_strand(), boost::bind(&CLASS::FUN, this, ##__VA_ARGS__)))

} // namespace rpc
} // namespace rpcboost

