#ifndef ACC_TYPE_H
#define ACC_TYPE_H

#include <string>
#include <vector>
#include <map>
#include "./accEnum.h"
#include <json_fwd.hpp>

using accDate = std::string;

struct ApplicationSubscription
{
    public:
        // Vendor client Id
        std::string vendorClientId;
        // Client reference
        std::string clientReference; 
        // Subscription status
        SubscriptionStatus subscriptionStatus;
        // Subscription Cancelled date
        accDate cancellationDateTime;
        // Subscription Activation date
        accDate activationDateTime;
        // Subscription Create date
        accDate createdDateTime;
        // Subscription Expired date
        accDate expiredDateTime;
        // Subscription Expiry date
        accDate expiryDateTime;
        // Application key identifier
        std::string subscriptionToken;
};
void to_json(nlohmann::json& j, const ApplicationSubscription& p);
void from_json(const nlohmann::json& j, ApplicationSubscription& p);

// Wrapper object containing affiliate relation details
struct AffiliateRelation
{
    // The affiliate relation status
    AffiliateRelationStatus status;
    // ID of user
    std::string vendorClientId;
};
void to_json(nlohmann::json& j, const AffiliateRelation& p);
void from_json(const nlohmann::json& j, AffiliateRelation& p);

// Wrapper object containing vendor name and redirect url
struct VendorDetails
{
    public:
        // URL to be redirected to
        std::string redirectUrl;
        // Vendor name
        std::string vendorName;
        // Internal id of the application
        long appVersionId;
};
void to_json(nlohmann::json& j, const VendorDetails& p);
void from_json(const nlohmann::json& j, VendorDetails& p);

// Wrapper object containing UserVendorSessionToken, RefreshToken and optionally a Subscription Token if one was created
struct VendorAccessTokenInfo
{
    public:
        // Object containing the vendor client id and optionally some subscription information
        ApplicationSubscription application_subscription;
        // Token used to refresh the session token in future;
        std::string refresh_token;
        // How long until the token expires
        long expires_in;
        // Type of the token
        TokenType token_type;
        // Session token used by web vendors
        std::string access_token;
};
void to_json(nlohmann::json& j, const VendorAccessTokenInfo& p);
void from_json(const nlohmann::json& j, VendorAccessTokenInfo& p);


// Wrapper object containing details of how a subscription should be created
struct SubscriptionOptions
{
    public:
        // Any client reference for this subscription token request.
        std::string client_reference;
        // An existing subscription token that the caller wishes to be activated instead of creating a new one. 
        std::string subscription_token;
        // How many days should a created subscription last for. Open ended subscription created if value not provided. 
        int subscription_length;
};
void to_json(nlohmann::json& j, const SubscriptionOptions& p);
void from_json(const nlohmann::json& j, SubscriptionOptions& p);

// Wrapper object containing authorisation code and redirect URL for web vendors
struct AuthorisationResponse
{
    public:
        // URL to redirect the user to the vendor page
        std::string redirectUrl;
        // The authorisation code
        std::string authorisationCode;
};
void to_json(nlohmann::json& j, const AuthorisationResponse& p);
void from_json(const nlohmann::json& j, AuthorisationResponse& p);

// Currency rate
struct CurrencyRate
{
    public:
        // Exchange rate for the currency specified in the request
        double rate;
        // Three letter ISO 4217 code
        std::string currencyCode;
};
void to_json(nlohmann::json& j, const CurrencyRate& p);
void from_json(const nlohmann::json& j, CurrencyRate& p);

// TimeRange
struct TimeRange
{
    public:
        // to, format: ISO 8601
        accDate to;
        // from, format: ISO 8601);
        accDate from;
};

// Summary of a cleared order.
struct StatementLegacyData
{
    public:
        // Currently returns same value as avgPrice. Once released will display the average matched price of the bet with no rounding applied
        double avgPriceRaw;
        // In the instance of a dead heat, this field will indicate the number of winners involved in the dead heat (null otherwise);
        double deadHeatPriceDivisor;
        // Win or loss
        WinLose winLose;
        // The unique reference Id assigned to account deposit and withdrawals.
        long transactionId;
        // Debit or credit
        std::string transactionType;
        // accDate and time at the bet portion was settled
        accDate startDate;
        // Name of the selection
        std::string selectionName;
        // Id of the selection (this will be the same for the same selection across markets);
        long selectionId;
        // accDate and time of bet placement
        accDate placedDate;
        // Market type. For account deposits and withdrawals, marketType is set to NOT_APPLICABLE.
        MarketType marketType;
        // Market Name. For card transactions, this field indicates the type of card transaction (deposit, deposit fee, or withdrawal);.
        std::string marketName;
        // The winning amount to which commission is applied.
        double grossBetAmount;
        // Full Market Name. For card payment items, this field contains the card name
        std::string fullMarketName;
        // Event Type
        long eventTypeId; 
        // Please note: this is the Id of the market without the associated exchangeId
        long eventId;
        // Commission rate on market
        std::string commissionRate;
        // Exchange, Market on Close SP bet, or Limit on Close SP bet.
        std::string betCategoryType;
        // Back or lay
        std::string betType;
        // The amount of the stake of your bet. (0 for commission payments or deposit/withdrawals);
        double betSize;
        // The average matched price of the bet (null if no part has been matched);
        double avgPrice;
};
void to_json(nlohmann::json& j, const StatementLegacyData& p);
void from_json(const nlohmann::json& j, StatementLegacyData& p);

// Summary of a cleared order.
struct StatementItem
{
    public:
        // Set of fields originally returned from APIv6. Provided to facilitate migration from APIv6 to API-NG, and ultimately onto itemClass and itemClassData
        StatementLegacyData legacyData;
        // Key value pairs describing the current statement item. The set of keys will be determined by the itemClass
        std::map<std::string,std::string> itemClassData;
        // Class of statement item. This value will determine which set of keys will be included in itemClassData
        ItemClass itemClass;
        // Account balance.
        double balance;
        // The amount of money the balance is adjusted by
        double amount;
        // The date and time of the statement item, eg. equivalent to settledData for an exchange bet statement item. (in ISO-8601 format, not translated);
        accDate itemDate;
        // An external reference, eg. equivalent to betId in the case of an exchange bet statement item.
        std::string refId;
};
void to_json(nlohmann::json& j, const StatementItem& p);
void from_json(const nlohmann::json& j, StatementItem& p);

// A container representing search results.
struct AccountStatementReport
{
    public:
        // Indicates whether there are further result items beyond this page.
        bool moreAvailable;
        // The list of statement items returned by your request.
        std::vector<StatementItem> accountStatement;
};
void to_json(nlohmann::json& j, const AccountStatementReport& p);
void from_json(const nlohmann::json& j, AccountStatementReport& p);

// Response for Account details.
struct AccountDetailsResponse
{
    public:
        // The customer's country of residence (ISO 2 Char format);
        std::string countryCode; 
        // The Betfair points balance.
        int pointsBalance;
        // User Discount Rate.
        double discountRate;
        // User Time Zonea
        std::string timezone;
        // Region based on users zip/postcode (ISO 3166-1 alpha-3 format);. Defaults to GBR if zip/postcode cannot be identified.
        std::string region;
        // Locale Code.
        std::string localeCode;
        // Last Name.
        std::string lastName;
        // First Name.
        std::string firstName;
        // Default user currency Code. See Currency Parameters for minimum bet sizes relating to each currency.
        std::string currencyCode;
};
void to_json(nlohmann::json& j, const AccountDetailsResponse& p);
void from_json(const nlohmann::json& j, AccountDetailsResponse& p);

// Response for retrieving available to bet.
struct AccountFundsResponse
{
    public:
        // The Betfair points balance
        int pointsBalance; 
        // User Discount Rate.
        double discountRate;
        // Exposure limit.
        double exposureLimit;
        // Sum of retained commission.
        double retainedCommission;
        // Current exposure.
        double exposure;
        // Amount available to bet.
        double availableToBetBalance;
};
void to_json(nlohmann::json& j, const AccountFundsResponse& p);
void from_json(const nlohmann::json& j, AccountFundsResponse& p);

// Describes a version of an external application
struct DeveloperAppVersion
{
    public:
        // Private unique string provided to the Vendor that they pass with certain calls to confirm their identity. 
        std::string vendorSecret;
        // Public unique string provided to the Vendor that they can use to pass to the Betfair API in order to identify themselves.
        std::string vendorId;
        // Indicates whether the application version is currently active
        bool active;
        // Indicates whether the application version needs explicit management by the software owner. A value of false indicates, this is a version meant for personal developer use.
        bool ownerManaged;
        // Indicates whether the application version needs explicit subscription
        bool subscriptionRequired;
        // Indicates whether the data exposed by platform services as seen by this application key is delayed or realtime.
        bool delayData;
        // The unqiue application key associated with this application version
        std::string applicationKey;
        // The version identifier string such as 1.0, 2.0. Unique for a given application.
        std::string version;
        // The unique Id of the application version
        long versionId;
        // The user who owns the specific version of the application
        std::string owner;
};
void to_json(nlohmann::json& j, const DeveloperAppVersion& p);
void from_json(const nlohmann::json& j, DeveloperAppVersion& p);

// Describes developer/vendor specific application
struct DeveloperApp
{
    public:
        // The application versions (including application keys);
        std::vector<DeveloperAppVersion> appVersions;
        // A unique id of this application
        long appId;
        // The unique name of the application
        std::string appName;
};
void to_json(nlohmann::json& j, const DeveloperApp& p);
void from_json(const nlohmann::json& j, DeveloperApp& p);

// Subscription token information
struct SubscriptionTokenInfo
{
    public:
        // Subscription status
        SubscriptionStatus subscriptionStatus;
        // Subscription Cancelled date
        accDate cancellationDateTime;
        // Subscription Expired date
        accDate expiredDateTime;
        // Subscription Expiry date
        accDate expiryDateTime;
        // Subscription Activated date
        accDate activatedDateTime;
        // Subscription token
        std::string subscriptionToken;
};
void to_json(nlohmann::json& j, const SubscriptionTokenInfo& p);
void from_json(const nlohmann::json& j, SubscriptionTokenInfo& p);

// Application subscription details
struct AccountSubscription
{
    public:
        // Application version Id
        std::string applicationVersionId;
        // Application name
        std::string applicationName;
        // List of subscription token details
        std::vector<SubscriptionTokenInfo> subscriptionTokens;
};
void to_json(nlohmann::json& j, const AccountSubscription& p);
void from_json(const nlohmann::json& j, AccountSubscription& p);

// Application subscription history details
struct SubscriptionHistory
{
    public:
        // Client reference
        std::string clientReference; 
        // Subscription status
        SubscriptionStatus subscriptionStatus;
        // Subscription Cancelled date
        accDate cancellationDateTime;
        // Subscription Activation date
        accDate activationDateTime;
        // Subscription Create date
        accDate createdDateTime;
        // Subscription Expired date
        accDate expiredDateTime;
        // Subscription Expiry date
        accDate expiryDateTime;
        // Application key identifier
        std::string subscriptionToken;
};
void to_json(nlohmann::json& j, const SubscriptionHistory& p);
void from_json(const nlohmann::json& j, SubscriptionHistory& p);

// Transfer operation response
struct TransferResponse
{
    public:
        // The id of the transfer transaction that will be used in tracking the transfers between the wallets
        std::string transactionId;
};
void to_json(nlohmann::json& j, const TransferResponse& p);
void from_json(const nlohmann::json& j, TransferResponse& p);

struct bfAccountAPINGException
{
    std::string requestUUID;
    std::string errorCode;
    std::string errorDetails;

    bool empty() const { return requestUUID.empty() && errorCode.empty() && errorDetails.empty();}
    void setEmpty() { requestUUID = std::string(); errorCode = std::string(); errorDetails = std::string(); }
};
void to_json(nlohmann::json& j, const bfAccountAPINGException& p);
void from_json(const nlohmann::json& j, bfAccountAPINGException& p);

struct bfDetail
{
    std::string exceptionname;
    bfAccountAPINGException AccountAPINGException;

    bool empty() const { return exceptionname.empty() && AccountAPINGException.empty();}
    void setEmpty() { exceptionname = std::string(); AccountAPINGException.setEmpty(); }
};
void to_json(nlohmann::json& j, const bfDetail& p);
void from_json(const nlohmann::json& j, bfDetail& p);


struct bfExceptionResponse
{
    std::string faultcode;
    std::string faultstring;
    bfDetail detail;

    bool empty() const { return faultcode.empty() && faultstring.empty() && detail.empty();}
};
void to_json(nlohmann::json& j, const bfExceptionResponse& p);
void from_json(const nlohmann::json& j, bfExceptionResponse& p);


// LOGIN, KEEP_ALIVE, LOGOUT
struct authKeepAlive
{
    public:
        std::string token;
        std::string product;
        authStatus status;
        authError error;
};
void to_json(nlohmann::json& j, const authKeepAlive& p);
void from_json(const nlohmann::json& j, authKeepAlive& p);

#endif
