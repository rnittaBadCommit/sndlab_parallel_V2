#include "RecievedMsg.hpp"

namespace rnitta
{



RecievedMsg::RecievedMsg()
{
}

RecievedMsg::RecievedMsg(const std::string content, const int client_fd)
	: content_(content), client_fd_(client_fd)
{
}

RecievedMsg RecievedMsg::operator=(const RecievedMsg &other)
{
	if (this == &other)
		return (*this);

	content_ = other.content_;
	client_fd_ = other.client_fd_;
	return (*this);
}


const std::string& RecievedMsg::getContent() const
{ return (content_); }

void RecievedMsg::setContent( const std::string& _content )
{ content_ = _content; }


}