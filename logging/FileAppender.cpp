#include "FileAppender.h"
#include "../ConfigFileParser.h"

using namespace std;

namespace blacksun {
	FileAppender::FileAppender() {
		ConfigFileParser config;
		config.read();
		string logFile = config.getValue("blacksunConfig.logging.logFile.<xmltext>");
	}

	void FileAppender::write(string message) {

	}

	int FileAppender::getType() {
		return APPENDER_TYPE_FILE;
	}
}
