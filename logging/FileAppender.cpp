#include "FileAppender.h"
#include <boost/property_tree/xml_parser.hpp>

using namespace std;
using namespace boost;
using namespace property_tree;
using namespace xml_parser;

namespace fs = boost::filesystem;

namespace blacksun {
	FileAppender::FileAppender() {
		ptree config;
		read_xml("conf/config.xml", config, trim_whitespace && no_comments && no_concat_text);
		fs::path logFile = fs::path(config.get<string>("blacksunConfig.logging.logFile.<xmltext>"));
		fs::path logDir(logFile);
		logDir = logDir.remove_filename();

		if(!fs::exists(logDir)) {
			fs::create_directories(logDir);
		}

		stream = new fs::ofstream(logFile, std::ios_base::app);
	}

	FileAppender::~FileAppender() {
		delete stream;
	}

	void FileAppender::write(string message) {
		*stream << message << endl;
	}

	int FileAppender::getType() {
		return APPENDER_TYPE_FILE;
	}
}
