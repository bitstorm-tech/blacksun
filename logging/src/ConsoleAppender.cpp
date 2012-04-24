#include "ConsoleAppender.h"
#include <iostream>

using namespace std;

namespace blacksun {
	void ConsoleAppender::write(string message) {
		cout << message << endl;
	}

	int ConsoleAppender::getType() {
		return APPENDER_TYPE_CONSOLE;
	}
}
