#include "Sniffer.h"
#include <boost/asio.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <listen_ip> <port>" << std::endl;
        return 1;
    }

    std::string listen_ip = argv[1];
    unsigned short port = static_cast<unsigned short>(std::stoi(argv[2]));

    try {
        boost::asio::io_context io_context;
        Sniffer sniffer(io_context, listen_ip, port);
        sniffer.start();
        io_context.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

