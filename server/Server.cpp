#include "Server.h"
#include <boost/asio.hpp>

using namespace std;
using namespace boost;
using namespace asio;
using namespace ip;

namespace blacksun {

	Server::Server() : logger("Server") {
	}

	void Server::start() {
		logger.info("starting server");

		io_service io_service;
		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 4711));

		while(true) {
			logger.info("listening for new connection...");

			tcp::socket socket(io_service);
			acceptor.listen();
			acceptor.accept(socket);
			write(socket, buffer("welcome!"));

			logger.info("client connected");


		}

		logger.info("shutdown server");
	}

}
