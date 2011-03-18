#include "Client.h"
#include <iostream>

using namespace std;

namespace blacksun {

	Client::Client() : logger("Client") {
	}

	void Client::start() {
		logger.info("starting client");
		logger.info("stopping client");
	}

}
