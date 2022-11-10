#include "RecieveRequest.hpp"

using namespace rnitta;

int main(int argc, char **argv)
{
	RecieveRequest recieveRequest;

	if (argc == 1)
		return (0);

	std::cout << "status: [" << recieveRequest.parseRequest(argv[1]) << "]" << std::endl;
	std::cout << "method: [" << recieveRequest.getMethod() << "]" << std::endl;
	std::cout << "header: [" << recieveRequest.getHeader() << "]" << std::endl;
	std::cout << "body: [" << recieveRequest.getBody() << "]" << std::endl;
}