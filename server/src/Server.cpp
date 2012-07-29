#include "Server.h"
#include "ConfigFileParser.h"

using namespace std;
using namespace boost;
using namespace asio;
using namespace ip;

namespace blacksun {

	Server::Server() :
	_logger("Server"),
	_ioService(new io_service)
	{}

	void Server::start() {
		init();
		
		io_service::work worker(*_ioService);

		_logger.info("starting server");
		_ioService->poll();
		_logger.info("IO Service started");

		tcp::acceptor acceptor(*_ioService, tcp::endpoint(tcp::v4(), _port));
		/**
		while(true) {

			//tcp::socket socket(_ioService);
			//acceptor.listen();
			//acceptor.accept(socket);
			//tcp_connection::pointer new_connection = tcp_connection::create(acceptor.get_io_service());
			//acceptor.async_accept(new_connection->socket(), boost::bind(&tcp_server::handle_accept, this, new_connection, boost::asio::placeholders::error));
			//write(socket, buffer("welcome!"));
			//_logger.info("client connected");
		}
		*/

		_logger.info("shutdown server");
	}

	void Server::init() {
		ConfigFileParser configFile;
		configFile.read();
		const string portString = configFile.getValue("blacksunConfig.server.port.<xmltext>");
		_port = atoi(portString.c_str());
		
		stringstream sstream;
		sstream << "listening on port ";
		sstream << _port;
		sstream << " for new connections";
		_logger.info( sstream.str() );
	}
}
