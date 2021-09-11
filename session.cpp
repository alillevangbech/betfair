#include "./session.h"
#include "./util.h"
#include "./json.h"
#include <cpr/cpr.h>

// Response<DeveloperApp>* Session::createDeveloperAppKeys (/* const std::string& appName */)
// {
// 	Response<DeveloperApp>* result = new Response<DeveloperApp>();
// 	const std::string urlBase = "https://api.betfair.com/exchange/account/rest/v1.0/";
// 
// 	std::string method = urlBase + "getAccountFunds/";
// 	json body;
// 
// 	cpr::Header genericHeaders = {
// 		{"X-Authentication", *this->sessionId},
// 		{"X-Application", appKey},
// 		{"Content-Type","application/json"},
// 		{"Content-Length", std::to_string(body.dump().length())},
// 		{"Accept", "application/json"},
// 		{"Host", "api.betfair.com"},
// 	};
// 
// 	cpr::Response r = cpr::Post(cpr::Url{method},
// 			genericHeaders,
// 			cpr::Body{body.dump()});
// 
// 	Response<AccountFundsResponse> bfResp = Response<AccountFundsResponse>();
// 	json j = json::parse(r.text);
// 
// 	std::cout << r.status_code << std::endl;
// 	std::cout << r.text << std::endl;
// 
// 	switch (static_cast<statusCode>(r.status_code))
// 	{
// 		case statusCode::VALID: /* FALLTHROUGH */
// 			std::cout << "haha" << std::endl;
// 			bfResp.ToType(j);
// 			break;
// 		case statusCode::EXCEPTION: /* FALLTHROUGH */
// 		case statusCode::ERROR: /* FALLTHROUGH */
// 			bfResp.ToException(j);
// 			break;
// 		case statusCode::UNKNOWN: /* FALLTHROUGH */  
// 		default:
// 			break;
// 	};
// 
// 
// 	auto text = keepAliveRequest(appKey, sessionId);
// 	json fuck = text;
// 
// 
// 	std::cout << fuck.dump() << std::endl;
// 	return 0;
// 
// }


Response<authKeepAlive>* Session::keepAliveRequest(/*const std::string& appKey, const std::string& sessionId*/)
{
	Response<authKeepAlive>* result = new Response<authKeepAlive>();
	std::string url = std::string("https://identitysso.betfair.com/api/keepAlive");
	cpr::Payload authBody = {{"username", *this->m_username}, {"password", *this->m_password}};
	cpr::Header authHeaders = {
		{"Content-Type","application/x-www-form-urlencoded"},
		{"Content-Length", std::to_string(authBody.GetContent(cpr::CurlHolder()).length())},
		{"Accept", "application/json"},
		{"X-Application", *m_appKey},
		{"X-Authentication", *m_sessionId},
		{"Connection", "keep-alive"},
	};

	// TODO: Log request;
	cpr::Response r = cpr::Post(cpr::Url{url}, authHeaders, authBody);
	// TODO: Log response;

	try
	{
		result->m_statusCode = static_cast<statusCode>(r.status_code);

		if (result->m_statusCode == statusCode::VALID)
		{
			result->m_bfData = nlohmann::json(r.text);
		}
		else
		{
			result->m_bfException = nlohmann::json(r.text);
		}

	}
	catch (nlohmann::json::parse_error&)
	{
		// TODO: log parsing error;
	}

	return result;
};

