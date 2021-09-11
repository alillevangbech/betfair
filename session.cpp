#include "./session.h"
#include "./response.h"
#include "./util.h"
#include "./json.h"
#include "./cpr.h"

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
	std::string url = std::string("https://identitysso.betfair.com/api/keepAlive");

	auto cprResponse = AuthPostRequest(*this, url);
	TranslateCprResponse(result, cprResponse);
	return result;
};

