#include "FileAppender.h"

using namespace std;

namespace blacksun {
	FileAppender::FileAppender() {
	}

	void FileAppender::write(string message) {

	}

	int FileAppender::getType() {
		return APPENDER_TYPE_FILE;
	}
}
