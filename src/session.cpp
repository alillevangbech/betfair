#include <cstddef>
#include <string>

#include "./session.h"
#include "./response.h"
#include "./util.h"
#include "./json.h"
#include "./cpr.h"

Session::Session() : m_username(nullptr), m_password(nullptr), m_sessionId(nullptr), m_appName(nullptr), m_appKey(nullptr)
{
	m_baseurl = new std::string("https://api.betfair.com/exchange/account/rest/v1.0/");
}

Session::~Session()
{
	delete this->m_baseurl;
	delete this->m_sessionId;
	delete this->m_appKey;
	delete this->m_appName;
	delete this->m_username;
	delete this->m_password;
}

Response<DeveloperApp>* Session::createDeveloperAppKeys (/* const std::string& appName */)
{
	Response<DeveloperApp>* result = new Response<DeveloperApp>();
	std::string url = *this->m_baseurl + "getAccountFunds/";
	std::string body = std::string();

	auto cprResponse = PostRequest(*this, url, body);
	TranslateCprResponse(result, cprResponse);
	return result;
}


Response<authKeepAlive>* Session::keepAliveRequest(/*const std::string& appKey, const std::string& sessionId*/)
{
	Response<authKeepAlive>* result = new Response<authKeepAlive>();
	std::string url = std::string("https://identitysso.betfair.com/api/keepAlive/");

	auto cprResponse = AuthPostRequest(*this, url);
	TranslateCprResponse(result, cprResponse);
	return result;
};

