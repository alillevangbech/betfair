#include <cpr/curl_container.h>
#include <cpr/payload.h>
#include <nlohmann/detail/conversions/to_json.hpp>
#include <ratio>
#include <string>
#include <vector>
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
#include "args.h"
#include <iostream>

using json = nlohmann::json;
std::string authRequest(const std::string& appKey);
std::string keepAliveRequest(const std::string& appKey, const std::string& sessionId);

int main()
{
    std::string sessionId = "NuA1b4fT6LhS39W0TC8liDAVAnKJfZFLaizHy7kx7jY=";
    std::string appName = "BetfairAnalytics";
    std::string appId = "88578";
    std::string url_base = "https://api.betfair.com/exchange/account/rest/v1.0/";
    
    auto req = keepAliveRequest(appId, sessionId);
    std::cout << req << std::endl;

    // use case specific
/*
    std::string method = "getAccountDetails/";
    json body;

    cpr::Header genericHeaders = {
        {"X-Authentication", session_id},
        {"Content-Type","application/json"},
        {"Content-Length", std::to_string(body.dump().length())},
        {"Accept", "application/json"},
        {"Host", "api.betfair.com"}
    };


    cpr::Response r = cpr::Post(cpr::Url{url_base + method},
                                genericHeaders,
                                cpr::Body{body.dump()});
    std::cout << r.text << std::endl;
    json output = json::parse(r.text);
    BetFairResponse bfr = output.get<BetFairResponse>();
    std::cout << output << std::endl;
    */

    return 0;
}

std::string keepAliveRequest(const std::string& appKey, const std::string& sessionId)
{
    //auth
    std::string auth_global_url = "https://identitysso.betfair.com/api/keepAlive";
    std::string user = "alexanderlillevangbech@gmail.com";
    std::string pass = "Khjiyu867";
    cpr::Payload authBody = {{"username",user},{"password",pass}};
    cpr::Header authHeaders = {
        {"Content-Type","application/x-www-form-urlencoded"},
        {"Content-Length", std::to_string(authBody.GetContent(cpr::CurlHolder()).length())},
        {"Accept", "application/json"},
        {"X-Application", appKey},
        {"X-Authentication", sessionId},
        {"Connection", "keep-alive"},
    };
     cpr::Response r = cpr::Post(cpr::Url{auth_global_url},
                                authHeaders,
                                authBody);

    return r.text;
};

std::string authRequest(const std::string& appKey)
{
    //auth
    std::string auth_global_url = "https://identitysso.betfair.com/api/login";
    std::string user = "alexanderlillevangbech@gmail.com";
    std::string pass = "Khjiyu867";
    cpr::Payload authBody = {{"username",user},{"password",pass}};
    cpr::Header authHeaders = {
        {"Content-Type","application/x-www-form-urlencoded"},
        {"Content-Length", std::to_string(authBody.GetContent(cpr::CurlHolder()).length())},
        {"Accept", "application/json"},
        {"X-Application", appKey},
        {"Connection", "keep-alive"},
    };
     cpr::Response r = cpr::Post(cpr::Url{auth_global_url},
                                authHeaders,
                                authBody);

    return r.text;
};
