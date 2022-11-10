#include "Config.hpp"

namespace rnitta
{


Config::Config()
{

}

Config::Config( const Config& other )
{
	*this = other;
}

Config::~Config()
{

}

Config& Config::operator=( const Config& other)
{
	if (this == &other)
		return (*this);

	childServerConf_vec_ = other.childServerConf_vec_;

	return (*this);
}

const std::vector<Config::childServerConf>& Config::getChildServerConf_vec() const
{ return (childServerConf_vec_); }

void Config::importConfig( const std::string& _config_path )
{
	std::ifstream _ifs(_config_path);
	std::string _buf;

    if (_ifs.fail())
        throw std::runtime_error("Error: Config Class: couldn't open the config file(" + _config_path + ")");

	std::size_t _pos;
	std::size_t _count_line = 0;
	std::regex _regex_number("[0-9]");
	std::string _line;
	std::string _ip;
	int _Eb;

    while (getline(_ifs, _buf)) {
		++_count_line;
		_line = trim(_buf);
		if (_line[0] == '#')	// # means "comment out"
			continue ;
		if (_line == "")
			continue;

        _pos = _line.find(" ");
		if (_pos == std::string::npos)
			throw std::runtime_error("Error: Config Class: invalid Config (line: " + std::to_string(_count_line) + ")\n"
										+ "syntax: [Server IP] [Eb]");
		_ip = _line.substr(0, _pos);
		if (check_ip_(_ip) == ERROR)
			throw std::runtime_error("Error: Config Class: invalid IP Address (line: " + std::to_string(_count_line) + ")\n"
										+ "syntax: [Server IP] [Eb]");
		try {_Eb = std::stoi(_line.substr(_pos));}
		catch ( const std::exception& e)
		{
			throw std::runtime_error("Error: Config Class: invalid Eb (line: " + std::to_string(_count_line) + ")\n"
										+ "syntax: [Server IP] [Eb]");
		}
		childServerConf_vec_.push_back(childServerConf(_ip, _Eb));
    }
    std::cout << "childServerConf_vec_.size(): " << childServerConf_vec_.size() << std::endl;
}

Config::status Config::check_ip_( const std::string _ip )
{
	std::string _number = "0123456789";
	std::string::size_type _pos = 0;

	if (_number.find(_ip[0]) == std::string::npos)	// .168.2.100: ERROR
		return (ERROR);

	for (int i = 0; i < 3; ++i)
	{
		_pos = _ip.find_first_not_of(_number, _pos);
		if (_ip[_pos] != '.')
			return (ERROR);
		++_pos;
		if (_ip[_pos] == '.')	// 192..2.100: ERROR
			return (ERROR);
	}
	if (_ip.find_first_of(_number, _pos) == std::string::npos)	// 192.168.2. : ERROR
		return (ERROR);
	if (_ip.find_first_not_of(_number, _pos) != std::string::npos)	// 192.168.2.100a: ERROR
		return (ERROR);

	return (OK);
}



}	// namespace rnitta
