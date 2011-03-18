#pragma once

#include "../utils/logging/Logger.h"

namespace blacksun {

	class Client {
	public:
		Client();
		void start();

	private:
		Logger logger;
	};

}
