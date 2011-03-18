#include "CmdArguments.h"
#include <iostream>
#include <sstream>

using namespace std;

namespace blacksun {

	void CmdArguments::parse(int numOfArgs, char* arguments[]) {
		for(int i = 0; i < numOfArgs; ++i) {
			string arg(arguments[i]);
			argList.push_front(arg);
		}
	}

	bool CmdArguments::contains(string value) {
		list<string>::iterator result = find(argList.begin(), argList.end(), value);
		return result != argList.end();
	}

	string CmdArguments::toString() {
		list<string>::iterator it = argList.begin();

		stringstream stream;

		while(it != argList.end()) {
			stream << "Argument: '";
			stream << *it++;
			stream << "'";
			stream << endl;
		}

		return stream.str();
	}

}
