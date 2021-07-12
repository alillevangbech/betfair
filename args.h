#include <nlohmann/json.hpp>
#include <string>

// BETFAIR ARGS
struct Arg_CreateDeveloperAppKeys;

// BETFAIR TYPES
struct Type_AccountAPINGExceptionType;

// BETFAIR MISC
struct Misc_BetFairResponse;
struct Misc_detail;

struct Args_CreateDeveloperAppKeys
{
    public:
        std::string appName;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Args_CreateDeveloperAppKeys, appName);

struct AccountAPINGExceptionType
{
    public:
        std::string requestUUID;
        std::string errorCode;
        std::string errorDetails;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AccountAPINGExceptionType, requestUUID, errorCode, errorDetails);

struct detailType
{
    public:
        std::string exceptionname;
        AccountAPINGExceptionType AccountAPINGException;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(detailType, exceptionname, AccountAPINGException);

struct BetFairResponse
{
    public:
        std::string faultcode;
        std::string faultstring;
        detailType detail;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BetFairResponse, faultcode, faultstring, detail);

