#include "utils.hpp"

namespace rnitta
{


std::string trim( const std::string _src, const char *_trimCharList)
{
	std::string ret;
	std::string::size_type _left = _src.find_first_not_of(_trimCharList);

	if (_left != std::string::npos)
	{
		std::string::size_type _right = _src.find_last_not_of(_trimCharList);
		ret = _src.substr(_left, _right - _left + 1);
	}

	return (ret);
}


}	// namespace rnitta
