#include "Sniffer.h"

Sniffer::Sniffer(boost::asio::io_context& io_context, const std::string& listen_ip, unsigned short port)
    : socket_(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::make_address(listen_ip), port)),
      buffer_(1024) {
    std::cout << "Listening on " << listen_ip << ":" << port << std::endl;
}

void Sniffer::start() {
    receive_packet();
}

void Sniffer::receive_packet() {
    socket_.async_receive_from(
        boost::asio::buffer(buffer_), remote_endpoint_,
        [this](const boost::system::error_code& error, std::size_t bytes_transferred) {
            handle_receive(error, bytes_transferred);
        });
}

void Sniffer::handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred) {
    if (!error) {
        std::cout << "Received packet from " << remote_endpoint_.address().to_string()
                  << ":" << remote_endpoint_.port() << std::endl;
        std::cout << "Data: " << std::string(buffer_.begin(), buffer_.begin() + bytes_transferred) << std::endl;
    } else {
        std::cerr << "Error receiving packet: " << error.message() << std::endl;
    }

    // Continue listening for packets
    receive_packet();
}



