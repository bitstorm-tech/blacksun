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

		io_service io_service;
		tcp::resolver resolver(io_service);
		tcp::resolver::query query("localhost", "blacksun-servers");
		resolver.resolve(query);

		logger.info("stopping client");
	}

}
