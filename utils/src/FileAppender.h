#pragma once

#include "Appender.h"
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

namespace blacksun {
	class FileAppender : public Appender {
	public:
		FileAppender();
		~FileAppender();
		void write(std::string message);
		int getType();

	private:
		boost::filesystem::ofstream* stream;
	};
}
