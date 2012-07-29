#pragma once

#include <boost/asio.hpp>
#include "Logger.h"

namespace blacksun {

	class Server {
	public:
		Server();
		void start();
		void init();

	private:
		Logger _logger;
		int _port;
		boost::shared_ptr<boost::asio::io_service> _ioService;
	};

}
