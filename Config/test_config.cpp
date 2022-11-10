#include "Config.hpp"

using namespace rnitta;

int main(int argc, char **argv)
{
	std::cout << argc << std::endl;
	if (argc < 2)
		return (0);

	std::cout << "here" << std::endl;
	Config config;
	try
	{
		config.importConfig(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
