#ifndef STRINGCONVERTER
#define STRINGCONVERTER

#include <sstream>

class StringConverterHelper
{
public:
	template<typename T>
	static std::string toString(const T &subject)
	{
		std::ostringstream ss;
		ss << subject;
		return ss.str();
	}

	template<typename T>
	static T fromString(const std::string &subject)
	{
		std::istringstream ss(subject);
		T target;
		ss >> target;
		return target;
	}
};


#endif	//#ifndef STRINGCONVERTER
