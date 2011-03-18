#include "Server.h"
#include "../utils/logging/Logger.h"
#include <iostream>
#include <sstream>

using namespace std;

namespace blacksun {

	void Server::start() {
		Logger logger("Server");

		logger.info("starting server");

		for(int i = 0; i < 10; ++i) {
			stringstream stream;
			stream << "got connection [";
			stream << i;
			stream << "]";
			logger.info(stream.str());
		}

		logger.info("shutdown server");
	}

}
