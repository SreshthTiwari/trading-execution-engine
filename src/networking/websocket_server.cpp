#include "websocket_server.hpp"
#include <iostream>
#include <thread>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

void handle_client(tcp::socket socket)
{
    // handle client connection
    std::cout << "new client connected\n";
}

void start_websocket_server()
{
    io_service io_service;
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 8080));

    std::cout << "server listening on port 8080\n";

    while (true)
    {
        tcp::socket socket(io_service);
        acceptor.accept(socket);
        std::thread(handle_client, std::move(socket)).detach();
    }
}
