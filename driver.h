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

