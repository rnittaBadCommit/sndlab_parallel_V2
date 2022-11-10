#include "RecieveRequest.hpp"
#include "CreateRequest.hpp"

using namespace rnitta;

int main(int argc, char **argv)
{
	if (argc < 4)
		return (0);

	std::cout << "test CreateRequest" << std::endl;
	CreateRequest createRequest;
	createRequest.setMethod(argv[1]);
	createRequest.setHeader(argv[2]);
	createRequest.setBody(argv[3]);
	std::cout << "request: [" << createRequest.getRequest() << "]" << std::endl;


	std::cout << "test RecieveRequest" << std::endl;
	RecieveRequest recieveRequest;
	recieveRequest.parseRequest(createRequest.getRequest());
	std::cout << "method: [" << recieveRequest.getMethod() << "]" << std::endl;
	std::cout << "header: [" << recieveRequest.getHeader() << "]" << std::endl;
	std::cout << "body: [" << recieveRequest.getBody() << "]" << std::endl;
}
