#include "FileAppender.h"
#include <boost/property_tree/xml_parser.hpp>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost;
using namespace property_tree;
using namespace xml_parser;

namespace fs = boost::filesystem;

namespace blacksun {
	FileAppender::FileAppender() {
		ptree config;
		read_xml("conf/config.xml", config, trim_whitespace && no_comments && no_concat_text);
		string logFile = config.get<string>("blacksunConfig.logging.logFile.<xmltext>");
		cout << "logFile = " << logFile << endl;
		fs::path logDir(logFile);
		fs::create_directories(logFile);
	}

	void FileAppender::write(string message) {

	}

	int FileAppender::getType() {
		return APPENDER_TYPE_FILE;
	}
}
