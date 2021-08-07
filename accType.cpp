#include <json.hpp>
#include "./accType.h"

using accDate = std::string;
using json = nlohmann::json;

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ApplicationSubscription, vendorClientId, clientReference, subscriptionStatus, cancellationDateTime, activationDateTime, createdDateTime, expiredDateTime, expiryDateTime, subscriptionToken);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AffiliateRelation, status, vendorClientId);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(VendorDetails, redirectUrl, vendorName, appVersionId)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(VendorAccessTokenInfo, application_subscription, refresh_token, expires_in, token_type, access_token);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SubscriptionOptions, client_reference, subscription_token, subscription_length);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AuthorisationResponse, redirectUrl, authorisationCode);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(CurrencyRate, currencyCode, rate);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TimeRange, to, from);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(StatementLegacyData, avgPriceRaw, deadHeatPriceDivisor, winLose, transactionId, transactionType, startDate, selectionName, selectionId, placedDate, marketType, marketName, grossBetAmount, fullMarketName, eventTypeId, eventId, commissionRate, betCategoryType, betType, betSize, avgPrice);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(StatementItem, legacyData, itemClassData, itemClass, balance, amount, itemDate, refId);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AccountStatementReport, moreAvailable, accountStatement);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AccountDetailsResponse, countryCode, pointsBalance, discountRate, timezone, region, localeCode, lastName, firstName, currencyCode);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AccountFundsResponse, pointsBalance, discountRate, exposureLimit, retainedCommission, exposure, availableToBetBalance);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(DeveloperAppVersion, vendorSecret, vendorId, active, ownerManaged, subscriptionRequired, delayData, applicationKey, version, versionId, owner);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(DeveloperApp, appVersions, appId, appName);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SubscriptionTokenInfo, subscriptionStatus, cancellationDateTime, expiredDateTime, expiryDateTime, activatedDateTime, subscriptionToken);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AccountSubscription, applicationVersionId, applicationName, subscriptionTokens);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SubscriptionHistory, clientReference, subscriptionStatus, cancellationDateTime, activationDateTime, createdDateTime, expiredDateTime, expiryDateTime, subscriptionToken);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TransferResponse, transactionId);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(bfAccountAPINGException, requestUUID, errorCode, errorDetails);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(bfDetail, exceptionname, AccountAPINGException);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(authKeepAlive, token, product, status, error);

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


