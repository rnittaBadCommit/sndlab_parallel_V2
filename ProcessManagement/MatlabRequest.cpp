#include "MatlabRequest.hpp"

namespace rnitta
{


// canonical
	MatlabRequest::MatlabRequest()
	{

	}

	MatlabRequest::MatlabRequest( const MatlabRequest& other )
	{
		*this = other;
	}

	MatlabRequest::~MatlabRequest()
	{

	}

	MatlabRequest&	MatlabRequest::operator=( const MatlabRequest& other )
	{
		if (this == &other)
			return (*this);

		eb_vec_ = other.eb_vec_;
		request_info_ = other.request_info_;
	}


// getter & setter
	const MatlabRequest::t_Eb_vec& MatlabRequest::get_Eb_vec() const
	{ return (eb_vec_); }

	const MatlabRequest::t_request_info& MatlabRequest::get_request_info() const
	{ return (request_info_); }

	void MatlabRequest::set_Eb_vec( const t_Eb_vec& _eb_vec )
	{ eb_vec_ = _eb_vec; }

	void MatlabRequest::set_request_info( const t_request_info& _request_info )
	{ request_info_ = _request_info; }


}	// namespace rnitta
