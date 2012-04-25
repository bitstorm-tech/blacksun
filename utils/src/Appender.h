#pragma once

#include <string>

namespace blacksun {
const int APPENDER_TYPE_CONSOLE = 0;
	const int APPENDER_TYPE_FILE = 1;

	class Appender {
	public:
		virtual void write(std::string message) = 0;
		virtual int getType() = 0;
	};
}
