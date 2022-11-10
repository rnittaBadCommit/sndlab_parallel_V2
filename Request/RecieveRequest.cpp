#include "RecieveRequest.hpp"

namespace rnitta
{


RecieveRequest::RecieveRequest()
: status_(METHOD)
{

}

RecieveRequest::RecieveRequest( const RecieveRequest& other )
{
	*this = other;
}

RecieveRequest::~RecieveRequest()
{

}

RecieveRequest& RecieveRequest::operator=( const RecieveRequest& other )
{
	if (this == &other)
		return (*this);

	status_ = other.status_;
	method_ = other.method_;
	header_ = other.header_;
	body_ = other.body_;
	save_ = other.save_;
	return (*this);
}

const std::string& RecieveRequest::getMethod() const
{ return (method_); }

const std::string& RecieveRequest::getHeader() const
{ return (header_); }

const std::string& RecieveRequest::getBody() const
{ return (body_); }

RecieveRequest::status RecieveRequest::parseRequest( const std::string& _request )
{
	save_ += _request;

	if (status_ == METHOD)
		setMethod_();
	if (status_ == HEADER_SIZE)
		setContentSize_(header_size_, HEADER);
	if (status_ == HEADER)
		setContent_(header_, header_size_, BODY_SIZE);
	if (status_ == BODY_SIZE)
		setContentSize_(body_size_, BODY);
	if (status_ == BODY)
		setContent_(body_, body_size_, COMPLETE);
	return (status_);
}

void RecieveRequest::setMethod_()
{
	std::size_t pos = save_.find(" ");
	if (pos == std::string::npos)
		return ;

	method_ = save_.substr(0, pos);
	save_.erase(0, pos + 1);
	status_ = HEADER_SIZE;
}

void RecieveRequest::setContent_( std::string& content, int content_size, status next_status )
{
	if (save_.size() < content_size)
		return ;

	content = save_.substr(0, header_size_);
	save_.erase(0, header_size_ + 1);
	status_ = next_status;
}

void RecieveRequest::setContentSize_( int& size, status nexe_status )
{
	std::size_t pos = save_.find(" ");
	if (pos == std::string::npos)
		return ;

	size = std::stoi(save_.substr(0, pos));
	save_.erase(0, pos + 1);
	status_ = nexe_status;
}




}	// namespace rnitta
