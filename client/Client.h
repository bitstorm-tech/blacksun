#pragma once

#include "Logger.h"

namespace blacksun {

	class Client {
	public:
		Client();
		void start();

	private:
		Logger logger;
	};

}
