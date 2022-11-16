u	#ifndef SOCKET_HPP
# define SOCKET_HPP

# include <iostream>
# include <vector>
# include <map>

# include <sys/socket.h> //アドレスドメイン
# include <sys/types.h>  //ソケットタイプ
# include <arpa/inet.h>  //バイトオーダの変換に利用
# include <poll.h>

# include "../utils/utils.hpp"
# include "../RecievedMsg/RecievedMsg.hpp"

namespace rnitta
{


class Socket
{
	public:
		// canonical & other constructors
			Socket();
			Socket( const Socket& other );
			~Socket();
			Socket& operator=( const Socket& other );

			Socket( const int port );

		// Func
			Server::RecievedMsg communicate_();

		// Exception
			class recieveMsgFromNewClient : public std::exception
			{
				public:
					recieveMsgFromNewClient(const int client_fd);
					const int client_fd;
			};

			class connectionHangUp : public std::exception
			{
				public:
					connectionHangUp(const int client_fd);
					const int client_fd;
			};

			class NoRecieveMsg : public std::exception
			{
			};

	private:
		typedef int clientfd;
		const int port_;
		int sockfd_;
		std::string IPAddress_;

		void setup_();
		void add_pollfd_(const int new_fd);
		void close_fd_(const int _fd, const int _i_poll_fd);
        void close_fd_(const int _fd);
		void send_msg_(int fd, const std::string msg);
		void register_new_client_(int sock_fd);
		RecievedMsg recieve_msg_from_connected_client_(int _connection);
        const std::string getIPAddress_() const;


};


}	// namespace rnitta

#endif
