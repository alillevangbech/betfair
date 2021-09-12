#ifndef CPR_H
#define CPR_H

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
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
	try
	{
		myResponse->m_statusCode = static_cast<statusCode>(cprReponse.status_code);

		if (myResponse->m_statusCode == statusCode::VALID)
		{
			std::cout << "Valid" << std::endl;
			nlohmann::json j = nlohmann::json::parse(cprReponse.text);
			std::cout << "Valid" << std::endl;
			*myResponse->m_bfData = j.get<T>();
			std::cout << "Valid" << std::endl;
		}
		else
		{
			std::cout << "Not Valid" << std::endl;
			myResponse->m_bfException = nlohmann::json(cprReponse.text);
		}

	}
	catch (nlohmann::json::parse_error&)
	{
		// TODO: log parsing error;
	}
	std::cout << "Valid" << std::endl;
}

#endif