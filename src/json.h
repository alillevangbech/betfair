#ifndef JSON_H
#define JSON_H

#include <string>
#include "acc_enum.h"
#include "acc_type.h"
#include <nlohmann/json.hpp>
#include "session.h"
#include <iostream>

 template<typename T>
 std::string sEnum(const T e)
 {
     nlohmann::json j = e;
     std::string res = j.dump();
     return res.substr(1,res.size() - 2);
 };


void to_json(nlohmann::json& j, const authKeepAlive& p);
void from_json(const nlohmann::json& j, authKeepAlive& p);
void to_json(nlohmann::json& j, const bfExceptionResponse& p);
void from_json(const nlohmann::json& j, bfExceptionResponse& p);
void to_json(nlohmann::json& j, const bfDetail& p);
void from_json(const nlohmann::json& j, bfDetail& p);
void to_json(nlohmann::json& j, const bfAccountAPINGException& p);
void from_json(const nlohmann::json& j, bfAccountAPINGException& p);
void to_json(nlohmann::json& j, const TransferResponse& p);
void from_json(const nlohmann::json& j, TransferResponse& p);
void to_json(nlohmann::json& j, const SubscriptionHistory& p);
void from_json(const nlohmann::json& j, SubscriptionHistory& p);
void to_json(nlohmann::json& j, const AccountSubscription& p);
void from_json(const nlohmann::json& j, AccountSubscription& p);
void to_json(nlohmann::json& j, const SubscriptionTokenInfo& p);
void from_json(const nlohmann::json& j, SubscriptionTokenInfo& p);
void to_json(nlohmann::json& j, const DeveloperApp& p);
void from_json(const nlohmann::json& j, DeveloperApp& p);
void to_json(nlohmann::json& j, const DeveloperAppVersion& p);
void from_json(const nlohmann::json& j, DeveloperAppVersion& p);
void to_json(nlohmann::json& j, const AccountFundsResponse& p);
void from_json(const nlohmann::json& j, AccountFundsResponse& p);
void to_json(nlohmann::json& j, const AccountDetailsResponse& p);
void from_json(const nlohmann::json& j, AccountDetailsResponse& p);
void to_json(nlohmann::json& j, const AccountStatementReport& p);
void from_json(const nlohmann::json& j, AccountStatementReport& p);
void to_json(nlohmann::json& j, const StatementItem& p);
void from_json(const nlohmann::json& j, StatementItem& p);
void to_json(nlohmann::json& j, const StatementLegacyData& p);
void from_json(const nlohmann::json& j, StatementLegacyData& p);
void to_json(nlohmann::json& j, const CurrencyRate& p);
void from_json(const nlohmann::json& j, CurrencyRate& p);
void to_json(nlohmann::json& j, const AuthorisationResponse& p);
void from_json(const nlohmann::json& j, AuthorisationResponse& p);
void to_json(nlohmann::json& j, const SubscriptionOptions& p);
void from_json(const nlohmann::json& j, SubscriptionOptions& p);
void to_json(nlohmann::json& j, const VendorAccessTokenInfo& p);
void from_json(const nlohmann::json& j, VendorAccessTokenInfo& p);
void to_json(nlohmann::json& j, const VendorDetails& p);
void from_json(const nlohmann::json& j, VendorDetails& p);
void to_json(nlohmann::json& j, const AffiliateRelation& p);
void from_json(const nlohmann::json& j, AffiliateRelation& p);
void to_json(nlohmann::json& j, const ApplicationSubscription& p);
void from_json(const nlohmann::json& j, ApplicationSubscription& p);

NLOHMANN_JSON_SERIALIZE_ENUM(statusCode, {
    {statusCode::UNKNOWN, "UNKNOWN"},
    {statusCode::VALID, "VALID"},
    {statusCode::ERROR, "ERROR"},
})

NLOHMANN_JSON_SERIALIZE_ENUM(MarketType,    {
        {MarketType::CEMPTY, ""},
        {MarketType::A, "A"},
        {MarketType::L, "L"},
        {MarketType::O, "O"},
        {MarketType::R, "R"},
        {MarketType::NOT_APPLICABLE, "NOT_APPLICABLE"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(authError,    {
        {authError::CEMPTY, ""},
        {authError::INPUT_VALIDATION_ERROR, "INPUT_VALIDATION_ERROR"},
        {authError::INTERNAL_ERROR, "INTERNAL_ERROR"},
        {authError::NO_SESSION, "NO_SESSION"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(authStatus,    {
        {authStatus::CEMPTY, ""},
        {authStatus::SUCCESS, "SUCCESS"},
        {authStatus::FAIL, "FAIL"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(SubscriptionStatus,    {
        {SubscriptionStatus::CEMPTY, ""},
        {SubscriptionStatus::EXPIRED, "EXPIRED"},
        {SubscriptionStatus::CANCELLED, "CANCELLED"},
        {SubscriptionStatus::UNACTIVATED, "UNACTIVATED"},
        {SubscriptionStatus::ACTIVATED, "ACTIVATED"},
        {SubscriptionStatus::ALL, "ALL"},
        });


NLOHMANN_JSON_SERIALIZE_ENUM(Status,    {
        {Status::CEMPTY, ""},
        {Status::SUCCESS, "SUCCESS"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(ItemClass, {
        {ItemClass::CEMPTY, ""},
        {ItemClass::UNKNOWN, "UNKNOWN"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(Wallet,    {
        {Wallet::CEMPTY, ""},
        {Wallet::UK, "UK"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(IncludeItem,   {
        {IncludeItem::CEMPTY, ""},
        {IncludeItem::POKER_ROOM, "POKER_ROOM"},
        {IncludeItem::EXCHANGE, "EXCHANGE"},
        {IncludeItem::DEPOSITS_WITHDRAWALS, "DEPOSITS_WITHDRAWALS"},
        {IncludeItem::ALL, "ALL"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(WinLose,   {
        {WinLose::CEMPTY, ""},
        {WinLose::COMMISSION_REVERSAL, "COMMISSION_REVERSAL"},
        {WinLose::RESULT_WON, "RESULT_WON"},
        {WinLose::RESULT_NOT_APPLICABLE, "RESULT_NOT_APPLICABLE"},
        {WinLose::RESULT_LOST, "RESULT_LOST"},
        {WinLose::RESULT_FIX, "RESULT_FIX"},
        {WinLose::RESULT_ERR, "RESULT_ERR"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(GrantType, {
        {GrantType::CEMPTY, ""},
        {GrantType::AUTHORIZATION_CODE, "AUTHORIZATION_CODE"},
        {GrantType::REFRESH_TOKEN, "REFRESH_TOKEN"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(AffiliateRelationStatus, {
        {AffiliateRelationStatus::CEMPTY, ""},
        {AffiliateRelationStatus::INVALID_USER, "INVALID_USER"},
        {AffiliateRelationStatus::AFFILIATED, "AFFILIATED"},
        {AffiliateRelationStatus::NOT_AFFILIATED, "NOT_AFFILIATED"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(TokenType, {
        {TokenType::CEMPTY, ""},
        {TokenType::BEARER, "BEARER"},
        });

#endif
