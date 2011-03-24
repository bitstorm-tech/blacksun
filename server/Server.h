#pragma once

#include "Logger.h"

namespace blacksun {

	class Server {
	public:
		Server();
		void start();

	private:
		Logger logger;
	};

}
