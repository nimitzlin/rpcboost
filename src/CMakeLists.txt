set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -DBOOST_LOG_DYN_LINK")
FIND_PACKAGE( Boost 1.55 COMPONENTS system thread date_time filesystem
regex iostreams locale log REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_library(rpcboost
			lib/common/server_manager.cpp
			lib/common/server_manager.hpp
			lib/common/server.cpp
			lib/common/server.hpp
			)
link_libraries(rpcboost)
ADD_EXECUTABLE(rpcmainexe rpcmain/main.cpp )

TARGET_LINK_LIBRARIES( rpcmainexe LINK_PUBLIC ${Boost_LIBRARIES} -lpthread -lm)
