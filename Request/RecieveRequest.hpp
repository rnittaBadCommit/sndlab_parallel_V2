#ifndef RECIEVEREQUEST_HPP
# define RECIEVEREQUEST_HPP

# include <iostream>
# include <map>
# include <string>

namespace rnitta
{


class RecieveRequest
{
	public:
		enum E_STATUS
		{
			METHOD,
			HEADER_SIZE,
			HEADER,
			BODY_SIZE,
			BODY,
			COMPLETE,
		};
		typedef E_STATUS status;

		// canonical
			RecieveRequest();
			RecieveRequest( const RecieveRequest& other );
			~RecieveRequest();
			RecieveRequest& operator=( const RecieveRequest& other );

		// getter & setter
			const std::string& getMethod() const;
			const std::string& getHeader() const;
			const std::string& getBody() const;

		// func
			status parseRequest( const std::string& _request );

	private:
		status status_;
		std::string method_;
		int header_size_;
		std::string header_;
		int body_size_;
		std::string body_;

		std::string save_;

		void setMethod_();
		void setContent_( std::string& content, int content_size, status nexe_status );
		void setContentSize_( int& size, status nexe_status );
};	// class RecieveRequest


}	// namespace rnitta

#endif
