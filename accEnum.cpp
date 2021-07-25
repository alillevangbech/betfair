#include <nlohmann/json.hpp>
#include "accEnum.h"

NLOHMANN_JSON_SERIALIZE_ENUM(MarketType,    {
        {MarketType::A, "A"},
        {MarketType::L, "L"},
        {MarketType::O, "O"},
        {MarketType::R, "R"},
        {MarketType::NOT_APPLICABLE, "NOT_APPLICABLE"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(authError,    {
        {authError::INPUT_VALIDATION_ERROR, "INPUT_VALIDATION_ERROR"},
        {authError::INTERNAL_ERROR, "INTERNAL_ERROR"},
        {authError::NO_SESSION, "NO_SESSION"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(authStatus,    {
        {authStatus::SUCCESS, "SUCCESS"},
        {authStatus::FAIL, "FAIL"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(SubscriptionStatus,    {
        {SubscriptionStatus::EXPIRED, "EXPIRED"},
        });


NLOHMANN_JSON_SERIALIZE_ENUM(Status,    {
        {Status::SUCCESS, "SUCCESS"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(ItemClass, {
        {ItemClass::UNKNOWN, "UNKNOWN"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(Wallet,    {
        {Wallet::UK, "UK"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(IncludeItem,   {
        {IncludeItem::POKER_ROOM, "POKER_ROOM"},
        {IncludeItem::EXCHANGE, "EXCHANGE"},
        {IncludeItem::DEPOSITS_WITHDRAWALS, "DEPOSITS_WITHDRAWALS"},
        {IncludeItem::ALL, "ALL"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(WinLose,   {
        {WinLose::COMMISSION_REVERSAL, "COMMISSION_REVERSAL"},
        {WinLose::RESULT_WON, "RESULT_WON"},
        {WinLose::RESULT_NOT_APPLICABLE, "RESULT_NOT_APPLICABLE"},
        {WinLose::RESULT_LOST, "RESULT_LOST"},
        {WinLose::RESULT_FIX, "RESULT_FIX"},
        {WinLose::RESULT_ERR, "RESULT_ERR"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(GrantType, {
        {GrantType::AUTHORIZATION_CODE, "AUTHORIZATION_CODE"},
        {GrantType::REFRESH_TOKEN, "REFRESH_TOKEN"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(AffiliateRelationStatus, {
        {AffiliateRelationStatus::INVALID_USER, "INVALID_USER"},
        {AffiliateRelationStatus::AFFILIATED, "AFFILIATED"},
        {AffiliateRelationStatus::NOT_AFFILIATED, "NOT_AFFILIATED"},
        });

NLOHMANN_JSON_SERIALIZE_ENUM(TokenType, {
        {TokenType::BEARER, "BEARER"},
        });
