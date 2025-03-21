cmake_minimum_required(VERSION 3.31.5)
project(TradingExecutionEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(trading_system
    src/core/order_book.cpp
    src/core/matching_engine.cpp
    src/market_data/market_data_interface.cpp
    src/networking/websocket_server.cpp
    src/main.cpp
)

target_link_libraries(trading_system -lboost_system -lpthread)
