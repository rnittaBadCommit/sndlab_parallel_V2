#include "CreateRequest.hpp"

using namespace rnitta;

int main(int argc, char **argv)
{
	if (argc < 4)
		return (0);

	CreateRequest createRequest;
	createRequest.setMethod(argv[1]);
	createRequest.setHeader(argv[2]);
	createRequest.setBody(argv[3]);
	std::cout << "request: [" << createRequest.getRequest() << "]" << std::endl;
}
