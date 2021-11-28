#include <nlohmann/json.hpp>
#include "./json.h"
#include "./util.h"
#include "./acc_enum.h"
#include "./acc_type.h"
#include <stdio.h>

using accDate = std::string;

// TransferResponse
void to_json(nlohmann::json& j, const TransferResponse& p)
{
    j = nlohmann::json{
        {"transactionId", p.transactionId},
    };
}

void from_json(const nlohmann::json& j, TransferResponse& p)
{
    j.at("transactionId").get_to(p.transactionId);
}

// AccountSubscription
void to_json(nlohmann::json& j, const AccountSubscription& p)
{
    j = nlohmann::json{
        {"applicationVersionId", p.applicationVersionId},
        {"applicationName", p.applicationName},
        {"subscriptionTokens", p.subscriptionTokens},
    };
}
void from_json(const nlohmann::json& j, AccountSubscription& p)
{
    j.at("applicationVersionId").get_to(p.applicationVersionId);
    j.at("applicationName").get_to(p.applicationName);
    j.at("subscriptionTokens").get_to(p.subscriptionTokens);
}

// DeveloperApp
void to_json(nlohmann::json& j, const DeveloperApp& p)
{
    j = nlohmann::json{
        {"appVersions", p.appVersions},
        {"appId", p.appId},
        {"appName", p.appName},
    };
}
void from_json(const nlohmann::json& j, DeveloperApp& p)
{
    j.at("appVersions").get_to(p.appVersions);
    j.at("appId").get_to(p.appId);
    j.at("appName").get_to(p.appName);
}

// DeveloperAppVersion
void to_json(nlohmann::json& j, const DeveloperAppVersion& p)
{
    j = nlohmann::json{
        {"vendorSecret", p.vendorSecret},
        {"vendorId", p.vendorId},
        {"active", p.active},
        {"ownerManaged", p.ownerManaged},
        {"subscriptionRequired", p.subscriptionRequired},
        {"delayData", p.delayData},
        {"applicationKey", p.applicationKey},
        {"version", p.version},
        {"versionId", p.versionId},
        {"owner", p.owner},
    };
}
void from_json(const nlohmann::json& j, DeveloperAppVersion& p)
{
    j.at("vendorSecret").get_to(p.vendorSecret);
    j.at("vendorId").get_to(p.vendorId);
    j.at("active").get_to(p.active);
    j.at("ownerManaged").get_to(p.ownerManaged);
    j.at("subscriptionRequired").get_to(p.subscriptionRequired);
    j.at("delayData").get_to(p.delayData);
    j.at("applicationKey").get_to(p.applicationKey);
    j.at("version").get_to(p.version);
    j.at("owner").get_to(p.owner);
}

// AccountDetailsResponse
void to_json(nlohmann::json& j, const AccountDetailsResponse& p)
{
    j = nlohmann::json{
        {"countryCode", p.countryCode},
        {"pointsBalance", p.pointsBalance},
        {"discountRate", p.discountRate},
        {"timezone", p.timezone},
        {"region", p.region},
        {"localeCode", p.localeCode},
        {"lastName", p.lastName},
        {"firstName", p.firstName},
        {"currencyCode", p.currencyCode},
    };
}
void from_json(const nlohmann::json& j, AccountDetailsResponse& p)
{
    j.at("countryCode").get_to(p.countryCode);
    j.at("pointsBalance").get_to(p.pointsBalance);
    j.at("discountRate").get_to(p.discountRate);
    j.at("timezone").get_to(p.timezone);
    j.at("region").get_to(p.region);
    j.at("localeCode").get_to(p.localeCode);
    j.at("lastName").get_to(p.lastName);
    j.at("firstName").get_to(p.firstName);
    j.at("currencyCode").get_to(p.currencyCode);
}

// AccountStatementReport
void to_json(nlohmann::json& j, const AccountStatementReport& p)
{
    j = nlohmann::json{
        {"moreAvailable", p.moreAvailable},
        {"accountStatement", p.accountStatement},
    };
}
void from_json(const nlohmann::json& j, AccountStatementReport& p)
{
    j.at("moreAvailable").get_to(p.moreAvailable);
    j.at("accountStatement").get_to(p.accountStatement);
}

// SubscriptionOptions
void to_json(nlohmann::json& j, const SubscriptionOptions& p)
{
    j = nlohmann::json{
        {"client_reference", p.client_reference},
        {"subscription_token", p.subscription_token},
        {"subscription_length", p.subscription_length},
    };
}
void from_json(const nlohmann::json& j, SubscriptionOptions& p)
{
    j.at("client_reference").get_to(p.client_reference);
    j.at("subscription_token").get_to(p.subscription_token);
    j.at("subscription_length").get_to(p.subscription_length);
}

// VendorDetails
void to_json(nlohmann::json& j, const VendorDetails& p)
{
    j = nlohmann::json{
        {"redirectUrl", p.redirectUrl},
        {"vendorName", p.vendorName},
        {"appVersionId", p.appVersionId},
    };
}
void from_json(const nlohmann::json& j, VendorDetails& p)
{
    j.at("redirectUrl").get_to(p.redirectUrl);
    j.at("vendorName").get_to(p.vendorName);
    j.at("appVersionId").get_to(p.appVersionId);
}

// AuthorisationResponse
void to_json(nlohmann::json& j, const AuthorisationResponse& p)
{
    j = nlohmann::json{
        {"redirectUrl", p.redirectUrl},
        {"authorisationCode", p.authorisationCode},
    };
}
void from_json(const nlohmann::json& j, AuthorisationResponse& p)
{
    j.at("redirectUrl").get_to(p.redirectUrl);
    j.at("authorisationCode").get_to(p.authorisationCode);
}

// TimeRange
void to_json(nlohmann::json& j, const CurrencyRate& p)
{
    j = nlohmann::json{
        {"currencyCode", p.currencyCode},
        {"rate", p.rate},
    };
}
void from_json(const nlohmann::json& j, CurrencyRate& p)
{
    j.at("currencyCode").get_to(p.currencyCode);
    j.at("rate").get_to(p.rate);
}

// TimeRange
void to_json(nlohmann::json& j, const TimeRange& p)
{
    j = nlohmann::json{
        {"to", p.to},
        {"from", p.from},
    };
}
void from_json(const nlohmann::json& j, TimeRange& p)
{
    j.at("to").get_to(p.to);
    j.at("from").get_to(p.from);
}

// AccountFundsResponse
void to_json(nlohmann::json& j, const AccountFundsResponse& p)
{
    j = nlohmann::json{
        {"pointsBalance", p.pointsBalance},
        {"discountRate", p.discountRate},
        {"exposureLimit", p.exposureLimit},
        {"retainedCommission", p.retainedCommission},
        {"exposure", p.exposure},
        {"availableToBetBalance", p.availableToBetBalance},
    };
}
void from_json(const nlohmann::json& j, AccountFundsResponse& p)
{
    j.at("pointsBalance").get_to(p.pointsBalance);
    j.at("discountRate").get_to(p.discountRate);
    j.at("exposureLimit").get_to(p.exposureLimit);
    j.at("retainedCommission").get_to(p.retainedCommission);
    j.at("exposure").get_to(p.exposure);
    j.at("availableToBetBalance").get_to(p.availableToBetBalance);
}

// SubscriptionHistory
void to_json(nlohmann::json& j, const SubscriptionHistory& p)
{
    j = nlohmann::json{
        {"clientReference", p.clientReference},
        {"subscriptionStatus", sEnum<SubscriptionStatus>(p.subscriptionStatus)},
        {"cancellationDateTime", p.cancellationDateTime},
        {"activationDateTime", p.activationDateTime},
        {"createdDateTime", p.createdDateTime},
        {"expiredDateTime", p.expiredDateTime},
        {"expiryDateTime", p.expiryDateTime},
        {"subscriptionToken", p.subscriptionToken},
    };
}
void from_json(const nlohmann::json& j, SubscriptionHistory& p)
{
    j.at("clientReference").get_to(p.clientReference);
    p.subscriptionStatus = j.at("subscriptionStatus");
    j.at("cancellationDateTime").get_to(p.cancellationDateTime);
    j.at("activationDateTime").get_to(p.activationDateTime);
    j.at("createdDateTime").get_to(p.createdDateTime);
    j.at("expiredDateTime").get_to(p.expiredDateTime);
    j.at("expiryDateTime").get_to(p.expiryDateTime);
    j.at("subscriptionToken").get_to(p.subscriptionToken);
}

// SubscriptionTokenInfo
void to_json(nlohmann::json& j, const SubscriptionTokenInfo& p)
{
    j = nlohmann::json{
        {"subscriptionStatus", sEnum<SubscriptionStatus>(p.subscriptionStatus)},
        {"cancellationDateTime", p.cancellationDateTime},
        {"expiredDateTime", p.expiredDateTime},
        {"expiryDateTime", p.expiryDateTime},
        {"activatedDateTime", p.activatedDateTime},
        {"subscriptionToken", p.subscriptionToken},
    };
}
void from_json(const nlohmann::json& j, SubscriptionTokenInfo& p)
{
    p.subscriptionStatus = j.at("subscriptionStatus");
    j.at("cancellationDateTime").get_to(p.cancellationDateTime);
    j.at("expiredDateTime").get_to(p.expiredDateTime);
    j.at("expiryDateTime").get_to(p.expiryDateTime);
    j.at("activatedDateTime").get_to(p.activatedDateTime);
    j.at("subscriptionToken").get_to(p.subscriptionToken);
}

// StatementItem
void to_json(nlohmann::json& j, const StatementItem& p)
{
    j = nlohmann::json{
        {"legacyData", p.legacyData},
        {"itemClassData", p.itemClassData},
        {"itemClass", sEnum<ItemClass>(p.itemClass)},
        {"balance", p.balance},
        {"amount", p.amount},
        {"itemDate", p.itemDate},
        {"refId", p.refId},
    };
}
void from_json(const nlohmann::json& j, StatementItem& p)
{
    j.at("legacyData").get_to(p.legacyData);
    j.at("itemClassData").get_to(p.itemClassData);
    p.itemClass = j.at("itemClass");
    j.at("balance").get_to(p.balance);
    j.at("amount").get_to(p.amount);
    j.at("itemDate").get_to(p.itemDate);
    j.at("refId").get_to(p.refId);
}

// StatementLegacyData
void to_json(nlohmann::json& j, const StatementLegacyData& p)
{
    j = nlohmann::json{
        {"avgPriceRaw", p.avgPriceRaw},
        {"deadHeatPriceDivisor", p.deadHeatPriceDivisor},
        {"winLose", sEnum<WinLose>(p.winLose)},
        {"transactionId", p.transactionId},
        {"transactionType", p.transactionType},
        {"startDate", p.startDate},
        {"selectionName", p.selectionName},
        {"selectionId", p.selectionId},
        {"placedDate", p.placedDate},
        {"marketType", sEnum<MarketType>(p.marketType)},
        {"marketName", p.marketName},
        {"grossBetAmount", p.grossBetAmount},
        {"fullMarketName", p.fullMarketName},
        {"eventTypeId", p.eventTypeId},
        {"commissionRate", p.commissionRate},
        {"betCategoryType", p.betCategoryType},
        {"betType", p.betType},
        {"betSize", p.betSize},
        {"avgPrice", p.avgPrice},
    };
}
void from_json(const nlohmann::json& j, StatementLegacyData& p)
{
    j.at("avgPriceRaw").get_to(p.avgPriceRaw);
    j.at("deadHeatPriceDivisor").get_to(p.deadHeatPriceDivisor);
    p.winLose = j.at("winLose");
    j.at("transactionId").get_to(p.transactionId);
    j.at("transactionType").get_to(p.transactionType);
    j.at("startDate").get_to(p.startDate);
    j.at("selectionName").get_to(p.selectionName);
    j.at("selectionId").get_to(p.selectionId);
    j.at("placedDate").get_to(p.placedDate);
    p.marketType = j.at("marketType");
    j.at("marketName").get_to(p.marketName);
    j.at("grossBetAmount").get_to(p.grossBetAmount);
    j.at("fullMarketName").get_to(p.fullMarketName);
    j.at("eventTypeId").get_to(p.eventTypeId);
    j.at("commissionRate").get_to(p.commissionRate);
    j.at("betCategoryType").get_to(p.betCategoryType);
    j.at("betType").get_to(p.betType);
    j.at("betSize").get_to(p.betSize);
    j.at("avgPrice").get_to(p.avgPrice);
}

// VendorAccessTokenInfo
void to_json(nlohmann::json& j, const VendorAccessTokenInfo& p)
{
    j = nlohmann::json{
        {"application_subscription", p.application_subscription},
        {"refresh_token", p.refresh_token},
        {"expires_in", p.expires_in},
        {"token_type", sEnum<TokenType>(p.token_type)},
        {"access_token", p.access_token},
    };
}
void from_json(const nlohmann::json& j, VendorAccessTokenInfo& p)
{
    j.at("application_subscription").get_to(p.application_subscription);
    j.at("refresh_token").get_to(p.refresh_token);
    j.at("expires_in").get_to(p.expires_in);
    p.token_type = j.at("token_type");
    j.at("access_token").get_to(p.access_token);
}

// AffiliateRelation
void to_json(nlohmann::json& j, const AffiliateRelation& p)
{
    j = nlohmann::json{
        {"vendorClientId", p.vendorClientId},
        {"status", sEnum<AffiliateRelationStatus>(p.status)},
    };
}
void from_json(const nlohmann::json& j, AffiliateRelation& p)
{
    j.at("vendorClientId").get_to(p.vendorClientId);
    p.status = j.at("status");
}

// ApplicationSubscription
void to_json(nlohmann::json& j, const ApplicationSubscription& p)
{
    j = nlohmann::json{
        {"vendorClientId", p.vendorClientId},
        {"clientReference", p.clientReference},
        {"subscriptionStatus", sEnum<SubscriptionStatus>(p.subscriptionStatus)},
        {"cancellationDateTime", p.cancellationDateTime},
        {"activationDateTime", p.activationDateTime},
        {"createdDateTime", p.createdDateTime},
        {"expiryDateTime", p.expiryDateTime},
        {"expiredDateTime", p.expiredDateTime},
        {"subscriptionToken", p.subscriptionToken}
    };
}
void from_json(const nlohmann::json& j, ApplicationSubscription& p)
{
    j.at("vendorClientId").get_to(p.vendorClientId);
    j.at("clientReference").get_to(p.clientReference);
    j.at("subscriptionStatus").get_to(p.subscriptionStatus);
    j.at("cancellationDateTime").get_to(p.cancellationDateTime);
    j.at("activationDateTime").get_to(p.activationDateTime);
    j.at("createdDateTime").get_to(p.createdDateTime);
    j.at("expiryDateTime").get_to(p.expiryDateTime);
    j.at("expiredDateTime").get_to(p.expiredDateTime);
    j.at("subscriptionToken").get_to(p.subscriptionToken);
}

// authKeepAlive
void to_json(nlohmann::json& j, const authKeepAlive& p)
{
    j = nlohmann::json{
        {"token", p.token},
        {"product", p.product},
        {"status", sEnum<authStatus>(p.status)},
        {"error", sEnum<authError>(p.error)}
    };
}
void from_json(const nlohmann::json& j, authKeepAlive& p)
{
    j.at("token").get_to(p.token);
    j.at("product").get_to(p.product);
    j.at("status").get_to(p.status);
    j.at("error").get_to(p.error);
}

// bfAccountAPINGException
void to_json(nlohmann::json& j, const bfAccountAPINGException& p) {
    j = nlohmann::json{
        {"requestUUID", p.requestUUID},
        {"errorCode", p.errorCode},
        {"errorDetails", p.errorDetails},
    };
}

void from_json(const nlohmann::json& j, bfAccountAPINGException& p) {
    j.at("requestUUID").get_to(p.requestUUID);
    j.at("errorCode").get_to(p.errorCode);
    j.at("errorDetails").get_to(p.errorDetails);
}

// bfDetail
void to_json(nlohmann::json& j, const bfDetail& p) {
    j = nlohmann::json{
        {"exceptionname", p.exceptionname},
    };
    if (empty(p.AccountAPINGException))
        j.push_back({"AccountAPINGException", nlohmann::json::object()});
    else
        j.push_back({"AccountAPINGException", p.AccountAPINGException});
}

void from_json(const nlohmann::json& j, bfDetail& p) {
    j.at("exceptionname").get_to(p.exceptionname);

    if (empty(j.at("AccountAPINGException")))
		setEmpty(p.AccountAPINGException);
    else
        j.at("AccountAPINGException").get_to(p.AccountAPINGException);
}

// bfExceptionResponse
void to_json(nlohmann::json& j, const bfExceptionResponse& p) {
    j = nlohmann::json{
        {"faultcode", p.faultcode},
        {"faultstring", p.faultstring}
    };
    if (empty(p.detail))
        j.push_back({"detail", nlohmann::json::object()});
    else
        j.push_back({"detail", p.detail});
}

void from_json(const nlohmann::json& j, bfExceptionResponse& p) {
    j.at("faultcode").get_to(p.faultcode);
    j.at("faultstring").get_to(p.faultstring);

    if (empty(j.at("detail")))
		setEmpty(p.detail);
    else
        j.at("detail").get_to(p.detail);
}
