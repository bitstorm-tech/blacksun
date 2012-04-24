#include "ConfigFileParser.h"
#include <string>
#include <boost/property_tree/xml_parser.hpp>

using namespace std;
using namespace boost;
using namespace property_tree;
using namespace xml_parser;

namespace blacksun {
	ConfigFileParser::ConfigFileParser() : logger("ConfigFileParser") {
	}

	void ConfigFileParser::read() {
		read(CONFIG_LOCATION);
	}

	void ConfigFileParser::read(string configFileLocation) {
		logger.info("Try to read config file: '" + configFileLocation + "'");

		try {
			read_xml(configFileLocation, config, trim_whitespace && no_comments && no_concat_text);
		} catch(...) {
			logger.error("Could not read config file: '" + configFileLocation + "'");
		}
	}

	string ConfigFileParser::getValue(string key) {
		string value = "";

		try {
			value = config.get<string>(key);
		} catch(...) {
			logger.warn("The following key is invalis: '" + key + "'");
		}

		return value;
	}
}
