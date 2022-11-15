#include "MainProcessManagement.hpp"

namespace rnitta
{


MainMatlabRequestManagement::MainMatlabRequestManagement()
{

}

MainMatlabRequestManagement::MainMatlabRequestManagement( const MainMatlabRequestManagement& other )
{
	*this = other;
}

MainMatlabRequestManagement::~MainMatlabRequestManagement()
{

}

MainMatlabRequestManagement& MainMatlabRequestManagement::operator=( const MainMatlabRequestManagement& other )
{
	if (this == &other)
		return (*this);

	
}


void MainMatlabRequestManagement::addMatlabRequest( const t_requestID _requestID,
													 const MatlabRequest& _request )
{ request_map_[_requestID] = _request; }

}	// namespace rnitta