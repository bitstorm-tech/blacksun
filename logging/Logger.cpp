#include "Logger.h"
#include "ConsoleAppender.h"
#include "FileAppender.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace std;
using namespace boost;
using namespace gregorian;
using namespace posix_time;
using namespace property_tree;
using namespace xml_parser;

namespace blacksun {
	list<Appender*> Logger::appenderList;
	//bool Logger::initialized = false;

	Logger::Logger(string className) {
		this->className = className;
		init();
	}

	Logger::~Logger() {

	}

	void Logger::init() {
		//if(!Logger::initialized) {
			ptree config;
			read_xml("conf/config.xml", config, trim_whitespace && no_comments && no_concat_text);
			string appenderTypes = config.get<string>("blacksunConfig.logging.appenderTypes.<xmltext>");
			tokenizer<> tokens(appenderTypes);
			tokenizer<>::iterator it = tokens.begin();

			while(it != tokens.end()) {
				if("FILE" == *it) {
					addAppender(new FileAppender());
				}

				if("CONSOLE" == *it) {
					addAppender(new ConsoleAppender);
				}

				++it;
			}
			//Logger::initialized = false;
		//}
	}

	void Logger::addAppender(Appender* appender) {
		list<Appender*>::iterator it = Logger::appenderList.begin();

		int type = appender->getType();

		while(it != Logger::appenderList.end()) {
			// only one appender of every type
			if(type == (*it++)->getType()) {
				return;
			}
		}

		Logger::appenderList.push_front(appender);
	}

	void Logger::info(string message) {
		log(format("INFO", message));
	}

	void Logger::warn(string message) {
		log(format("WARN", message));
	}

	void Logger::error(string message) {
		log(format("ERROR", message));
	}

	void Logger::log(string message) {
		list<Appender*>::iterator it = this->appenderList.begin();

		while(it != this->appenderList.end()) {
			(*it++)->write(message);
		}
	}

	string Logger::format(string logLevel, string message) {
		string space = "  ";

		if(logLevel == "ERROR") {
			space = " ";
		}

		stringstream stream;
		stream << getTimeString();
		stream << " ";
		stream << "[" << logLevel << "]";
		stream << space;
		stream << "[" << this->className << "]";
		stream << " ";
		stream << message;

		return stream.str();
	}

	string Logger::getTimeString() {
		stringstream stream;
		time_facet* facet(new time_facet("%Y-%m-%d %H:%M:%s"));
		stream.imbue(locale(stream.getloc(), facet));
		stream << microsec_clock::local_time();

		return stream.str();
	}
}
