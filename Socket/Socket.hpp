#ifndef SOCKET_HPP
# define SOCKET_HPP

# include <iostream>
# include <vector>
# include <map>
# include <set>

# include <sys/socket.h> //アドレスドメイン
# include <sys/types.h>  //ソケットタイプ
# include <arpa/inet.h>  //バイトオーダの変換に利用
# include <poll.h>
# include <cstring>
# include <unistd.h>

# include "../utils/utils.hpp"
# include "../RecievedMsg/RecievedMsg.hpp"

namespace rnitta
{


class Socket
{
	public:
		// typedef
			typedef int t_clientID;
			typedef int t_fd;

		// default parametaer
			static const int DEFAULT_PORT = 8080;
		// canonical & other constructors
			Socket();
			Socket( const Socket& other );
			~Socket();

			Socket( const int port );

		// Func
			RecievedMsg communicate_();

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
		static const int BUFFER_SIZE = 1 << 10;
		const int port_;
		int sockfd_;
		std::string IPAddress_;

        std::vector<struct pollfd> poll_fd_vec_;
        std::set<t_fd> registered_fd_set_;
		
        std::map<t_fd, std::string> msg_to_send_map_;

		void setup_();
		void add_pollfd_(const t_fd new_fd);
		int get_pollfd_vec_index( const t_fd fd );
		void close_fd_(const t_fd _fd, const int _i_poll_fd);
        void close_fd_(const t_fd _fd);
		void send_msg_(t_fd fd, const std::string msg);
		void register_new_client_(t_fd sock_fd);
		RecievedMsg recieve_msg_from_connected_client_(t_fd _connection);
        const std::string getIPAddress_() const;


};


}	// namespace rnitta

#endif
