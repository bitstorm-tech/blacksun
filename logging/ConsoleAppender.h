#pragma once

#include "Appender.h"
#include <string>

namespace blacksun {
	class ConsoleAppender : public Appender {
	public:
		void write(std::string message);
		int getType();
	};
}
