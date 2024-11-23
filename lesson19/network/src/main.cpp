#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>
#include <iostream>
#include <string>
#include <chrono>



using namespace std::chrono_literals;

#define PORT 2001


std::vector<char> vBuffer(20 * 1024);

void ClientReadDataDataFromServer(asio::ip::tcp::socket& socket) {
    socket.async_read_some(asio::buffer(vBuffer.data(), vBuffer.size()),
        [&](std::error_code ec, std::size_t length) {
            if (!ec) {
                std::cout << "\n\nread " << length << "bytes \n";

                for (int i = 0; i < length; ++i) {
                    std::cout << vBuffer[i];
                }

                std::string question;
                std::cout << "\nenter question " << std::endl;
                std::cin >> question;
                socket.write_some(asio::buffer(question.data(), question.size()), ec);
                if (ec) {
                    std::cerr << "fail" << std::endl;
                }

                ClientReadDataDataFromServer(socket);
            }
        }

    );
};

void serverFunc() {
    asio::error_code ec;
    asio::io_context context;

    // asio::ip::tcp::endpoint endpoint(asio::ip::make_address(asio::ip::address_v4{}, ec), 80); //"93.184.216.34" //"127.0.0.1"
    // asio::ip::tcp::socket socket(context);

    // socket.connect(endpoint, ec);



    asio::ip::tcp::acceptor acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), PORT));
    while (true)
    {
        asio::ip::tcp::socket socket(context);

        acceptor.accept(socket);

        int  messageCount = 10;
        while (--messageCount > 0)
        {
            size_t len = socket.read_some(asio::buffer(vBuffer), ec);

            if (!ec) {
                std::cout << "\nmessage from client " << vBuffer.data() << std::endl;
                std::string message = "hello from server. message received. " + std::to_string(messageCount);
                socket.write_some(asio::buffer(message.data(), message.size()), ec);
            }
            else {
                std::cout << "failed" << std::endl;
            }
            socket.wait(socket.wait_read);
        }

        socket.close();
    }
}

int main(int argc, char** argv) {
    if (argc == 1) {
        asio::error_code ec;
        asio::io_context context;


        asio::ip::tcp::endpoint endpoint(asio::ip::make_address("127.0.0.1", ec), PORT); //"93.184.216.34" //"127.0.0.1"
        asio::ip::tcp::socket socket(context);

        socket.connect(endpoint, ec);

        if (!ec) {
            std::cout << "connected" << std::endl;
        }
        else {
            std::cout << "failed" << std::endl;
        }

        if (socket.is_open()) {
            ClientReadDataDataFromServer(socket);
            std::string sRequest = "quest1";

            socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);

            context.run();
        }
    }
    else {
        serverFunc();

    }

    return 0;
}