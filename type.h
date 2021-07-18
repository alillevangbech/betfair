#include <nlohmann/json.hpp>
#include <string>
#include <vector>

struct Type_AccountAPINGException;
struct Type_TransferResponse;
struct Type_ApplicationSubscription; 
struct Type_SubscriptionHistory; 
struct Type_AccountSubscription;
struct Type_SubscriptionTokenInfo;

struct Type_SubscriptionTokenInfo 
{
    public:
        std::string subscriptionToken;
        std::string activatedDateTime;
        std::string expiryDateTime;
        std::string expiredDateTime;
        std::string cancellationDateTime;
        std::string subscriptionStatus; //subscription status
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Type_SubscriptionTokenInfo,subscriptionToken,activatedDateTime,expiryDateTime,expiredDateTime,cancellationDateTime,subscriptionStatus);

struct Type_AccountSubscription  
{
    public:
        std::vector<std::string> subscriptionTokens;
        std::string applicationName;
        std::string applicationVersionId;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Type_AccountSubscription,subscriptionTokens,applicationName,applicationVersionId);

struct Type_SubscriptionHistory 
{
    public:
        std::string subscriptionToken;
        std::string expiryDateTime; //date
        std::string expiredDateTime; //date
        std::string createdDateTime;
        std::string activationDateTime;
        std::string cancellationDateTime;
        std::string subscriptionStatus; //subscription status
        std::string clientReference;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Type_SubscriptionHistory,subscriptionToken,expiryDateTime,expiredDateTime,createdDateTime,activationDateTime,cancellationDateTime,subscriptionStatus,clientReference);

struct Type_ApplicationSubscription 
{
    public:
        std::string subscriptionToken;
        std::string expiryDateTime; //date
        std::string expiredDateTime; //date
        std::string createdDateTime;
        std::string activationDateTime;
        std::string cancellationDateTime;
        std::string subscriptionStatus; //subscription status
        std::string clientReference;
        std::string vendorClientId;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Type_ApplicationSubscription,subscriptionToken,expiryDateTime,expiredDateTime,createdDateTime,activationDateTime,cancellationDateTime,subscriptionStatus,clientReference,vendorClientId);

struct Type_TransferResponse 
{
    public:
        std::string transactionId;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Type_TransferResponse,transactionId);


struct Type_AccountAPINGException
{
    public:
        std::string requestUUID;
        std::string errorCode;
        std::string errorDetails;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Type_AccountAPINGException, requestUUID, errorCode, errorDetails);
