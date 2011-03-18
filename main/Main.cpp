#include "../utils/CmdArguments.h"
#include "../utils/ConfigFileParser.h"
#include "../server/Server.h"
#include "../client/Client.h"
#include "../utils/logging/Logger.h"
#include "../utils/logging/ConsoleAppender.h"
#include "../utils/logging/FileAppender.h"
#include <iostream>

using namespace std;
using namespace blacksun;

ConfigFileParser config;

int main(int argc, char* argv[]) {
	CmdArguments cmdArgs;
	cmdArgs.parse(argc, argv);

	Logger logger("Main");

	if(cmdArgs.contains("-s")) {
		Server server;
		server.start();
	} else if(cmdArgs.contains("-c")) {
		Client client;
		client.start();
	}

	return 0;
}
