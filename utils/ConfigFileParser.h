#pragma once

#include "logging/Logger.h"
#include <string>
#include <boost/property_tree/xml_parser.hpp>

namespace blacksun {
	const std::string CONFIG_LOCATION = "conf/config.xml";

	class ConfigFileParser {
	public:
		ConfigFileParser();
		std::string getValue(std::string key);
		void read();
		void read(std::string configFileLocation);

	private:
		boost::property_tree::ptree config;
		Logger logger;
	};
}
