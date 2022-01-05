#ifndef CPR_H
#define CPR_H

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include "cpr/ssl_options.h"
#include "session.h"
#include "json.h"
#include <iostream>


cpr::Response inline AuthPostRequest(const Session& session, const std::string& url)
{
	cpr::Payload authBody = {{"username", *session.m_username}, {"password", *session.m_password}};
	cpr::Header authHeaders = {
		{"Content-Type","application/x-www-form-urlencoded"},
		{"Content-Length", std::to_string(authBody.GetContent(cpr::CurlHolder()).length())},
		{"Accept", "application/json"},
		{"X-Application", *session.m_appKey},
		{"X-Authentication", *session.m_sessionId},
		{"Connection", "keep-alive"},
	};

	return cpr::Post(cpr::Url{url},
					 authBody,
					 authHeaders);

}

cpr::Response inline PostRequest(const Session& session, const std::string& url, const std::string& body)
{
	cpr::Header genericHeaders = {
		{"X-Authentication", *session.m_sessionId},
		{"X-Application", *session.m_appKey},
		{"Content-Type","application/json"},
		{"Content-Length", std::to_string(body.length())},
		{"Accept", "application/json"},
		{"Host", "api.betfair.com"},
	};

	return cpr::Post(cpr::Url{url},
					 cpr::Body{body},
					 genericHeaders);

}

template <typename T>
void TranslateCprResponse(Response<T>* myResponse, cpr::Response cprReponse)
{

	if (cprReponse.text.empty()) {
		std::cout << "betfair response has empty data" << std::endl;
		std::cout << "status: " << cprReponse.status_code << std::endl;
		std::cout << "error.message: " << cprReponse.error.message << std::endl;
		return;
	}

	try
	{
		myResponse->m_statusCode = static_cast<statusCode>(cprReponse.status_code);
		std::cout << "statusCode: " << sEnum(myResponse->m_statusCode) << std::endl;

		if (myResponse->m_statusCode == statusCode::VALID)
		{
			*myResponse->m_bfData = nlohmann::json::parse(cprReponse.text);
		}
		else
		{	
			*myResponse->m_bfException = nlohmann::json::parse(cprReponse.text);
		}

	}
	catch (nlohmann::json::parse_error&)
	{
		// TODO: log parsing error;
		std::cout << "parsing fuckup" << std::endl;
		std::cout << "text: " << cprReponse.text << std::endl;
		std::cout << "status: " << cprReponse.status_code << std::endl;
		std::cout << "error.message: " << cprReponse.error.message << std::endl;
	}
}

#endif
