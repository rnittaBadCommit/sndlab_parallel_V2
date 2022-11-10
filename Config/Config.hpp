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
			typedef std::pair<ip, Eb> childServerConf;

		// canonical
			Config();
			Config( const Config& other );
			~Config();
			Config& operator=( const Config& other );

		// getter
			const std::vector<childServerConf>& getChildServerConf_vec() const;

		// func
			void importConfig( const std::string& _config_path );

	private:
		enum E_STATUS
		{
			ERROR,
			OK,
		};
		typedef E_STATUS status;
		std::vector<childServerConf> childServerConf_vec_;
		status check_ip_( const std::string _ip );
};	// class Config


}	// namespace rnitta

#endif
