#include "Client.h"
#include "ConfigFileParser.h"
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <exception>

using namespace std;
using namespace boost;
using namespace asio;
using namespace ip;

namespace blacksun {

	Client::Client() : logger("Client") {
	}

	void Client::start() {
		try {
			logger.info("starting client");


			ConfigFileParser configFile;
			configFile.read();
			string port = configFile.getValue("blacksunConfig.server.port.<xmltext>");
			string host = configFile.getValue("blacksunConfig.server.host.<xmltext>");

			logger.info("try to establish connection to: " + host + ":" + port);

			io_service io_service;
			tcp::resolver resolver(io_service);
			tcp::resolver::query query(host, port);
			tcp::resolver::iterator it = resolver.resolve(query);
			tcp::socket socket(io_service);
			socket.connect(*it);
			boost::array<char, 512> array;
			size_t len = socket.read_some(buffer(array));

			stringstream stream;
			stream << "received: '";
			stream.write(array.data(), len);
			stream << "'";
			logger.info(stream.str());

			logger.info("stopping client");
		} catch(std::exception& e) {
			stringstream stream;
			stream << "could not establish connection to server because of: '";
			stream << e.what();
			stream << "'";
			logger.error(stream.str());
		}
	}

}
