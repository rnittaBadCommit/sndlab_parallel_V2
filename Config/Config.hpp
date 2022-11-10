#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <fstream>
# include <iostream>
# include <vector>
# include <regex>

# include "../utils/utils.hpp"

namespace rnitta
{


class Config
{
	public:
		// typedef
			typedef std::string ip;
			typedef int Eb;
			typedef std::pair<ip, Eb> childServer_conf;

		// canonical
			Config();
			Config( const Config& other );
			~Config();
			Config& operator=( const Config& other );

		// getter
			

		// func
			void importConfig( const std::string& _config_path );

	private:
		enum E_STATUS
		{
			ERROR,
			OK,
		};
		typedef E_STATUS status;
		std::vector<childServer_conf> childServer_conf_vec_;
		status check_ip_( const std::string _ip );
};	// class Config


}	// namespace rnitta

#endif
