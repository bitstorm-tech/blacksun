#include "Client.h"
#include <boost/asio.hpp>
#include <boost/array.hpp>

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
		tcp::resolver::query query("localhost", "4711");
		tcp::resolver::iterator it = resolver.resolve(query);
		tcp::socket socket(io_service);
		socket.connect(*it);
		array<char, 512> array;
		size_t len = socket.read_some(buffer(array));

		stringstream stream;
		stream << "received: '";
		stream.write(array.data(), len);
		stream << "'";
		logger.info(stream.str());

		logger.info("stopping client");
	}

}
