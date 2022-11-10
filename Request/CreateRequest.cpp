#include "CreateRequest.hpp"

namespace rnitta
{


CreateRequest::CreateRequest()
{

}

CreateRequest::CreateRequest( const CreateRequest& other )
{
	*this = other;
}

CreateRequest::~CreateRequest()
{

}

CreateRequest& CreateRequest::operator=( const CreateRequest& other )
{
	if (this == &other)
		return (*this);

	method_ = other.method_;
	header_ = other.header_;
	body_ = other.body_;
	return (*this);
}

// "[METHOD] [HEADER_SIZE] [HEADER] [BODY_SIZE] [BODY]"
std::string CreateRequest::getRequest() const
{
	status_map::const_iterator it_end = status_map_.end();
	for (status_map::const_iterator it_status = status_map_.begin();
		 it_status != it_end;
		 ++it_status)
	{
		if ((*it_status).second != SET)
			throw std::runtime_error("Error: CreateRequest Class: Request(" + (*it_status).first + ") is not set yet");
	}

	return (method_ + " " + std::to_string(header_.size()) + " " + header_
			 + " " + std::to_string(body_.size()) + " " + body_);
}

void CreateRequest::setMethod( const std::string& _method )
{ method_ = _method; }

void CreateRequest::setHeader( const std::string& _header )
{ header_ = _header; }

void CreateRequest::setBody( const std::string& _body )
{ body_ = _body; }


} // namespace rnitta

