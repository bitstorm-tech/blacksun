#include "CmdArguments.h"
#include "ConfigFileParser.h"
#include "Server.h"
#include "Client.h"
#include "Logger.h"
#include <iostream>

using namespace std;
using namespace blacksun;

int main(int argc, char* argv[]) {
	try {
		CmdArguments cmdArgs;
		cmdArgs.parse(argc, argv);

		Logger logger("Main");
		logger.info("Starting Blacksun...");

		if(cmdArgs.contains("-s")) {
			Server server;
			server.start();
		} else if(cmdArgs.contains("-c")) {
			Client client;
			client.start();
		} else {
			logger.info("Plese use one the following arguments: ");
			logger.info("-s for starting in server mode");
			logger.info("-c for starting in client mode");
		}
	} catch( std::exception &e ) { 
        cout << e.what(); 
    } 

	return 0;
}
