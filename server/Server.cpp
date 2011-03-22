#include "Server.h"
#include "Logger.h"
#include <boost/asio.hpp>

using namespace std;
using namespace boost;
using namespace asio;
using namespace ip;

namespace blacksun {

	void Server::start() {
		Logger logger("Server");

		logger.info("starting server");

		io_service io_service;
		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 4711));

		while(true) {
			logger.info("listening for new connection...");

			tcp::socket socket(io_service);
			acceptor.accept(socket);


		}

		logger.info("shutdown server");
	}

}
