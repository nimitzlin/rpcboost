set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -DBOOST_LOG_DYN_LINK")
FIND_PACKAGE( Boost 1.55 COMPONENTS system thread date_time filesystem
regex iostreams locale log REQUIRED )
FIND_PACKAGE(Protobuf)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS proto/rpctest.proto)

add_library(rpcboost
			lib/common/common.hpp
			lib/common/server_manager.cpp
			lib/common/server_manager.hpp
			lib/common/server.cpp
			lib/common/server.hpp
			lib/common/connection_manager.cpp
			lib/common/connection_manager.hpp
			lib/common/connection.cpp
			lib/common/connection.hpp

			lib/rpc/channel_request.hpp
			lib/rpc/channel_request.cpp
			lib/rpc/channel_request_parser.hpp
			lib/rpc/channel_request_parser.cpp
			lib/rpc/rpc_channel.hpp
			lib/rpc/rpc_channel.cpp
			)
add_library(rpcboost ${PROTO_SRCS} ${PROTO_HDRS})
link_libraries(rpcboost)
ADD_EXECUTABLE(rpcmainexe rpcmain/main.cpp )

TARGET_LINK_LIBRARIES( rpcmainexe LINK_PUBLIC ${Boost_LIBRARIES} -lpthread -lm)
