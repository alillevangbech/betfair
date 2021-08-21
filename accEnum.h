#ifndef ACC_ENUM_H
#define ACC_ENUM_H
// accEnum.cpp
#include <json_fwd.hpp>

enum class AffiliateRelationStatus
{
// Vendor client ID valid but not affiliated  
    NOT_AFFILIATED,
// Vendor client ID valid and affiliated     
    AFFILIATED,
// Provided vendor client ID is not valid    
    INVALID_USER,
};
void to_json(nlohmann::json& j, const AffiliateRelationStatus& p);
void from_json(const nlohmann::json& j, AffiliateRelationStatus& p);

enum class TokenType
{
// Token type used for Vendor Web API interactions for making requests on a customers behalf.    
    BEARER,
};
void to_json(nlohmann::json& j, const TokenType& p);
void from_json(const nlohmann::json& j, TokenType p);

enum class GrantType
{
// A token that can be used to create a new access token when using the Vendor Web API    
    REFRESH_TOKEN,
// Returned via the Vendor Web API token request.     
    AUTHORIZATION_CODE,
};
void to_json(nlohmann::json& j, const GrantType& p);
void from_json(const nlohmann::json& j, GrantType p);

enum class WinLose
{
// Record has been affected by a unsettlement. There is no impact on the balance for these records, this just a label to say that these are to be corrected. 
    RESULT_ERR,
// Record is a correction to the balance to reverse the impact of records shown as in error. If commission has been paid on the original settlement then there will be a second FIX record to reverse the commission. 
    RESULT_FIX,
// Loss
    RESULT_LOST,
// Amounts relating to commission payments.
    RESULT_NOT_APPLICABLE,
// Won
    RESULT_WON,
// Betfair have restored the funds to your account that it previously received from you in commission.
    COMMISSION_REVERSAL,
};
void to_json(nlohmann::json& j, const WinLose& p);
void from_json(const nlohmann::json& j, WinLose p);

enum class IncludeItem
{
// Include all items
    ALL,
// Include payments only
    DEPOSITS_WITHDRAWALS,
// Include exchange bets only
    EXCHANGE,
// Include poker transactions only
    POKER_ROOM,
};
void to_json(nlohmann::json& j, const IncludeItem& p);
void from_json(const nlohmann::json& j, IncludeItem p);

enum class Wallet
{
// The Global Exchange wallet
    UK,
};
void to_json(nlohmann::json& j, const Wallet& p);
void from_json(const nlohmann::json& j, Wallet p);

enum class ItemClass
{
// Statement item not mapped to a specific class. All values will be concatenated into a single key/value pair. The key will be 'unknownStatementItem' and the value will be a comma separated string. Please note: This is used to represent commission payment items.
    UNKNOWN,
};
void to_json(nlohmann::json& j, const ItemClass& p);
void from_json(const nlohmann::json& j, ItemClass p);

enum class Status
{
// Sucess status
    SUCCESS,
};
void to_json(nlohmann::json& j, const Status& p);
void from_json(const nlohmann::json& j, Status p);

enum class SubscriptionStatus
{
// Only expired subscriptions    
    EXPIRED,
// Only cancelled subscriptions  
    CANCELLED,
// Only unactivated subscriptions    
    UNACTIVATED,
// Only activated subscriptions  
    ACTIVATED,
// Any subscription status    
    ALL,
};
void to_json(nlohmann::json& j, const SubscriptionStatus& p);
void from_json(const nlohmann::json& j, SubscriptionStatus p);

// LOGIN, KEEP_ALIVE, LOGOUT

enum class authStatus
{
    SUCCESS,
    FAIL,
};
void to_json(nlohmann::json& j, const authStatus& p);
void from_json(const nlohmann::json& j, authStatus p);

enum class authError
{
    INPUT_VALIDATION_ERROR,
    INTERNAL_ERROR,
    NO_SESSION,
};
void to_json(nlohmann::json& j, const authError& p);
void from_json(const nlohmann::json& j, authError p);

// BETTING API
enum class MarketType
{
// Asian Handicap
    A,
// Line market
    L,
// Odds market    
    O,
// The market does not have an applicable marketType.  
    R,
// Odds market   
    NOT_APPLICABLE,
};
void to_json(nlohmann::json& j, const MarketType& p);
void from_json(const nlohmann::json& j, MarketType p);

#endif
