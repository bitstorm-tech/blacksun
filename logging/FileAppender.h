#pragma once

#include "Appender.h"

namespace blacksun {
	class FileAppender : public Appender {
	public:
		FileAppender();
		void write(std::string message);
		int getType();
	};
}
