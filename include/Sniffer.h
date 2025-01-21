#ifndef SNIFFER_H
#define SNIFFER_H

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <vector>

class Sniffer {
public:
    Sniffer(boost::asio::io_context& io_context, const std::string& listen_ip, unsigned short port);
    void start();

private:
    void receive_packet();
    void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred);

    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint remote_endpoint_;
    std::vector<char> buffer_;
};

#endif // SNIFFER_H
