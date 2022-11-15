#ifndef SENDREQUEST_HPP
# define SENDREQUEST_HPP

# include <iostream>
# include <map>

namespace rnitta
{

class CreateRequest
{
	public:
		// canonical
			CreateRequest();
			CreateRequest( const CreateRequest& other );
			~CreateRequest();
			CreateRequest& operator=( const CreateRequest& other );

		void clear();

		// create Request
			std::string getRequest() const;
			void setMethod( const std::string& _method );
			void setHeader( const std::string& _header );
			void setBody( const std::string& _body );

	private:
		enum E_STATUS
		{
			SET,
			UNSET,
		};

		// typedef int status;
		typedef std::map<std::string, E_STATUS> status_map;


		status_map status_map_;
		std::string method_;
		std::string header_;
		std::string body_;
};	// class SendRequest


}	// namespace rnitta

#endif
