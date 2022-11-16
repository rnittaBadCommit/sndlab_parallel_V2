#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <memory>    // shared_ptr
# include <array>

namespace rnitta
{


std::string trim( const std::string src, const char *trimCharList = " \t\v\r\n");
bool ExecCmd(const char* cmd, std::string& stdOut, int& exitCode);

}	// namespace rnitta

#endif