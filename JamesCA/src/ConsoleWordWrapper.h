#include <string>

class ConsoleWordWrapper
{
public:
	std::string text;
	static void formatString(std::string *text, int lineNumber);
};

