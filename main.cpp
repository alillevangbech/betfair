#include <algorithm>
#include <nlohmann/detail/conversions/to_json.hpp>
#include <string>
#include <vector>
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
#include "args.h"
#include <iostream>

using json = nlohmann::json;

int main()
{
    std::string session_id = "wqgNKEcv8tYZ6aHK/cvQD/XD3YfV7EaaIx2j7y0Ut94=";
    std::string appName = "BetfairAnalytics";
    std::string appId = "88578";
    std::string url_base = "https://api.betfair.com/exchange/account/rest/v1.0/";

    // use case specific

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
    /*
    json output = json::parse(r.text);
    BetFairResponse bfr = output.get<BetFairResponse>();
    std::cout << output << std::endl;
    */

    return 0;
}

