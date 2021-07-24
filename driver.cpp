#include <ratio>
#include <string>
#include <vector>
#include <memory>
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include "./accType.h"
#include "./accException.h"

using json = nlohmann::json;
std::string authRequest(const std::string& appKey);

// AccountFundsResponse getAccountFunds ()
enum class statusCode
{
    UNKNOWN = 0,
    VALID = 200,
    EXCEPTION = 400,
    ERROR = 404,
};

template <typename T>
class Response
{
    public:
        std::unique_ptr<T> m_bfType;
        std::unique_ptr<bfExceptionResponse> m_bfException;

        Response(){ m_bfType = std::unique_ptr<T>(nullptr); m_bfException = std::unique_ptr<bfExceptionResponse>(nullptr);};

        void ToType(const json& j)
        {
            if (m_bfType.operator->() == nullptr)
                m_bfType = std::unique_ptr<T>(new T);
            *m_bfType = j;
        };
        void ToException(const json& j)
        {
            if (m_bfException.operator->() == nullptr)
                m_bfException = std::unique_ptr<bfExceptionResponse>(new bfExceptionResponse);
            *m_bfException = j;
        };
};

int main()
    {
    const std::string sessionId = "cc3XACtZjDhDMyimFnyEUK7MOCAFi+JOrT+R4wHetp4=";
    const std::string appName = "BetfairAnalytics";
    const std::string appId = "88578";
    const std::string appKey = "VcwjIeTG67VJeQTZ";
    const std::string urlBase = "https://api.betfair.com/exchange/account/rest/v1.0/";
    
    std::string method = urlBase + "getAccountFunds/";
    json body;

    cpr::Header genericHeaders = {
        {"X-Authentication", sessionId},
        {"X-Application", appKey},
        {"Content-Type","application/json"},
        {"Content-Length", std::to_string(body.dump().length())},
        {"Accept", "application/json"},
        {"Host", "api.betfair.com"},
    };

    cpr::Response r = cpr::Post(cpr::Url{method},
            genericHeaders,
            cpr::Body{body.dump()});

    Response<AccountFundsResponse> bfResp = Response<AccountFundsResponse>();
    json j = json::parse(r.text);

    switch (static_cast<statusCode>(r.status_code))
    {
        case statusCode::VALID: /* FALLTHROUGH */
            std::cout << "haha" << std::endl;
            bfResp.ToType(j);
            break;
        case statusCode::EXCEPTION: /* FALLTHROUGH */
        case statusCode::ERROR: /* FALLTHROUGH */
            bfResp.ToException(j);
            break;
        case statusCode::UNKNOWN: /* FALLTHROUGH */  
        default:
            break;
    };

    std::cout << r.status_code << std::endl;
    std::cout << r.text << std::endl;

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
