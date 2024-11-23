#include <iostream>
#include <asio.hpp>

std::string responce(20*1024, ' ');

const int PORT = 2001;
void readyRead(asio::ip::tcp::socket& socket) {
	socket.async_read_some(asio::buffer(responce, responce.size()),
		[&socket](asio::error_code ec, size_t length) {
			std::cout << "read " << length << " bytes" << std::endl;
			std::cout << "result: \n" << responce << std::endl;
			//readyRead(socket);
			socket.close();
		}
	);
}

void serverFunc() {
	asio::error_code ec;
	asio::io_context context;
	asio::ip::tcp::acceptor acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), PORT));

}

int main(int argc, char ** argv) {
	asio::error_code ec;
	asio::io_context context;
	if (argc > 1) {//server
		serverFunc();


	}
	else { //client



		
		asio::ip::tcp::endpoint endpoint(asio::ip::make_address("93.184.215.14", ec), 80);
		asio::ip::tcp::socket socket(context);
		socket.connect(endpoint, ec);

		if (!ec)
		{
			std::cout << "connection success" << std::endl;
		}
		else {
			std::cerr << "connection failed" << std::endl;
		}

		if (socket.is_open()) {
			std::string request =
				"GET /index.html HTTP/1.1\r\n"
				"Host: example.com\r\n"
				"Connection: close\r\n\r\n";
			socket.write_some(asio::buffer(request.data(), request.length()), ec);

			if (!ec)
			{
				std::cout << "request success" << std::endl;
			}
			else {
				std::cerr << "request failed" << std::endl;
			}

			//socket.wait(socket.wait_read);

			//auto count = socket.available();

			readyRead(socket);
		}
	}
	context.run();
	
	return 0;
}