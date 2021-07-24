#include <string>
#include <json.hpp>

using json = nlohmann::json;

struct bfAccountAPINGException
{
    std::string requestUUID;
    std::string errorCode;
    std::string errorDetail;

    bool empty() const { return requestUUID.empty() && errorCode.empty() && errorDetail.empty();}
    void setEmpty() { requestUUID = std::string(); errorCode = std::string(); errorDetail = std::string(); }
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(bfAccountAPINGException, requestUUID, errorCode, errorDetail);

struct bfDetail
{
    std::string exceptionname;
    bfAccountAPINGException AccountAPINGException;

    bool empty() const { return exceptionname.empty() && AccountAPINGException.empty();}
    void setEmpty() { exceptionname = std::string(); AccountAPINGException.setEmpty(); }
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(bfDetail, exceptionname, AccountAPINGException);


struct bfExceptionResponse
{
    std::string faultcode;
    std::string faultstring;
    bfDetail detail;

    bool empty() const { return faultcode.empty() && faultstring.empty() && detail.empty();}
};

void to_json(json& j, const bfExceptionResponse& p) {
    j = json{
        {"faultcode", p.faultcode},
        {"faultstring", p.faultstring}
    };
    if (p.detail.empty())
        j.push_back({"detail", json::object()});
    else
        j.push_back({"detail", p.detail});
}

void from_json(const json& j, bfExceptionResponse& p) {
    j.at("faultcode").get_to(p.faultcode);
    j.at("faultstring").get_to(p.faultstring);

    if (j.at("detail").empty())
        p.detail.setEmpty();
    else
        j.at("detail").get_to(p.detail);
}


















