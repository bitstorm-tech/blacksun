#include "Client.h"
#include <boost/asio.hpp>

using namespace std;
using namespace boost;
using namespace asio;
using namespace ip;

namespace blacksun {

	Client::Client() : logger("Client") {
	}

	void Client::start() {
		logger.info("starting client");

		io_service service;
		tcp::resolver(service);
		tcp::resolver::query query("localhost");


		logger.info("stopping client");
	}

}
