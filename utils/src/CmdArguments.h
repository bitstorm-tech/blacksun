#pragma once

#include <list>
#include <algorithm>
#include <string>

namespace blacksun {

	class CmdArguments {
	private:
		std::list<std::string> argList;

	public:
		void parse(int numOfArgs, char* arguments[]);
		bool contains(std::string value);
		std::string toString();
	};

}
