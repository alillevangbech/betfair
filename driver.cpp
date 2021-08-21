#include <string>
#include "nlohmann/json.hpp"
#include <ratio>
#include <vector>
#include <memory>
#include <iostream>
#include "cpr/cpr.h"
#include "accType.h"
#include "accEnum.h"

using json = nlohmann::json;
authKeepAlive keepAliveRequest(const std::string& appKey, const std::string& sessionId);

enum class statusCode
{
    UNKNOWN = 0,
    VALID = 200,
    EXCEPTION = 400,
    ERROR = 404,
};

NLOHMANN_JSON_SERIALIZE_ENUM(statusCode, {
    {statusCode::UNKNOWN, "UNKNOWN"},
    {statusCode::VALID, "VALID"},
    {statusCode::EXCEPTION, "EXCEPTION"},
    {statusCode::ERROR, "ERROR"},
})

template<typename T>
std::string EnumToString(const T e)
{
    json j = e;
    std::string res = j.dump();
    return res.substr(1,res.size() - 2);
};

// AccountFundsResponse getAccountFunds ()

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

authKeepAlive keepAliveRequest(const std::string& appKey, const std::string& sessionId)
{
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

     json j = json::parse(r.text);
     authKeepAlive ret = j;

     return ret;
};

int main()
{
    const std::string sessionId = "B3IjR0QLUcknNr8OkT/V0DcnjGU0pbOC6p1SFgFuQPI=";
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

    std::cout << r.status_code << std::endl;
    std::cout << r.text << std::endl;

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


    //auto text = keepAliveRequest(appKey, sessionId);
    //std::cout << text.token << std::endl;
    //std::cout << text.product << std::endl;
    //std::cout << EnumToString<authStatus>(text.status) << std::endl;
    //std::cout << EnumToString<authError>(text.error) << std::endl;
    return 0;
}

