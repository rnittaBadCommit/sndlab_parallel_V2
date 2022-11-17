#ifndef RECIEVED_MSH
# define RECIEVED_MSH

# include <iostream>

namespace rnitta
{


class RecievedMsg
{
	public:
		// canonical & other constructors
			RecievedMsg();
			RecievedMsg( const RecievedMsg& other);
			~RecievedMsg();
			RecievedMsg operator=(const RecievedMsg &other);
			RecievedMsg(const std::string content, const int client_fd);

		// getter & setter
			const std::string& getContent() const;
			void setContent( const std::string& content );

	private:
		std::string content_;
		int client_fd_;
};


}

#endif