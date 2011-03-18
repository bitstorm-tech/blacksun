#pragma once

#include "Appender.h"
#include <string>
#include <list>

namespace blacksun {
	class Logger {
	public:
		Logger(std::string clazz);
		~Logger();
		void info(std::string message);
		void warn(std::string message);
		void error(std::string message);
		void addAppender(Appender* appender);
		void init();

	private:
		std::string className;
		std::string getTimeString();
		std::string format(std::string logLevel, std::string message);
		void log(std::string message);
		static std::list<Appender*> appenderList;
		//static bool initialized;
	};
}
