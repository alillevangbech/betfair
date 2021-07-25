#ifndef ACC_ENUM_H
#define ACC_ENUM_H
#include <nlohmann/json.hpp>



enum class AffiliateRelationStatus
{
// Vendor client ID valid but not affiliated  
    NOT_AFFILIATED,
// Vendor client ID valid and affiliated     
    AFFILIATED,
// Provided vendor client ID is not valid    
    INVALID_USER,
};
NLOHMANN_JSON_SERIALIZE_ENUM(AffiliateRelationStatus, {
                                                        {AffiliateRelationStatus::INVALID_USER, "INVALID_USER"},
                                                        {AffiliateRelationStatus::AFFILIATED, "AFFILIATED"},
                                                        {AffiliateRelationStatus::NOT_AFFILIATED, "NOT_AFFILIATED"},
                                                      });

enum class TokenType
{
// Token type used for Vendor Web API interactions for making requests on a customers behalf.    
    BEARER,
};
NLOHMANN_JSON_SERIALIZE_ENUM(TokenType, {
                                            {TokenType::BEARER, "BEARER"},
                                        });

enum class GrantType
{
// A token that can be used to create a new access token when using the Vendor Web API    
    REFRESH_TOKEN,
// Returned via the Vendor Web API token request.     
    AUTHORIZATION_CODE,
};
NLOHMANN_JSON_SERIALIZE_ENUM(GrantType, {
                                            {GrantType::AUTHORIZATION_CODE, "AUTHORIZATION_CODE"},
                                            {GrantType::REFRESH_TOKEN, "REFRESH_TOKEN"},
                                        });

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
NLOHMANN_JSON_SERIALIZE_ENUM(WinLose,   {
                                            {WinLose::COMMISSION_REVERSAL, "COMMISSION_REVERSAL"},
                                            {WinLose::RESULT_WON, "RESULT_WON"},
                                            {WinLose::RESULT_NOT_APPLICABLE, "RESULT_NOT_APPLICABLE"},
                                            {WinLose::RESULT_LOST, "RESULT_LOST"},
                                            {WinLose::RESULT_FIX, "RESULT_FIX"},
                                            {WinLose::RESULT_ERR, "RESULT_ERR"},
                                        });

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
NLOHMANN_JSON_SERIALIZE_ENUM(IncludeItem,   {
                                                {IncludeItem::POKER_ROOM, "POKER_ROOM"},
                                                {IncludeItem::EXCHANGE, "EXCHANGE"},
                                                {IncludeItem::DEPOSITS_WITHDRAWALS, "DEPOSITS_WITHDRAWALS"},
                                                {IncludeItem::ALL, "ALL"},
                                            });

enum class Wallet
{
// The Global Exchange wallet
    UK,
};
NLOHMANN_JSON_SERIALIZE_ENUM(Wallet,    {
                                            {Wallet::UK, "UK"},
                                        });

enum class ItemClass
{
// Statement item not mapped to a specific class. All values will be concatenated into a single key/value pair. The key will be 'unknownStatementItem' and the value will be a comma separated string. Please note: This is used to represent commission payment items.
    UNKNOWN,
};
NLOHMANN_JSON_SERIALIZE_ENUM(ItemClass, {
                                            {ItemClass::UNKNOWN, "UNKNOWN"},
                                        });

enum class Status
{
// Sucess status
    SUCCESS,
};
NLOHMANN_JSON_SERIALIZE_ENUM(Status,    {
                                            {Status::SUCCESS, "SUCCESS"},
                                        });

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
NLOHMANN_JSON_SERIALIZE_ENUM(SubscriptionStatus,    {
                                                        {SubscriptionStatus::EXPIRED, "EXPIRED"},
                                                    });

// LOGIN, KEEP_ALIVE, LOGOUT

enum class authStatus
{
    SUCCESS,
    FAIL,
};
NLOHMANN_JSON_SERIALIZE_ENUM(authStatus,    {
                                                        {authStatus::SUCCESS, "SUCCESS"},
                                                        {authStatus::FAIL, "FAIL"},
                                                    });
enum class authError
{
    INPUT_VALIDATION_ERROR,
    INTERNAL_ERROR,
    NO_SESSION,
};
NLOHMANN_JSON_SERIALIZE_ENUM(authError,    {
                                                        {authError::INPUT_VALIDATION_ERROR, "INPUT_VALIDATION_ERROR"},
                                                        {authError::INTERNAL_ERROR, "INTERNAL_ERROR"},
                                                        {authError::NO_SESSION, "NO_SESSION"},
                                                    });

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
NLOHMANN_JSON_SERIALIZE_ENUM(MarketType,    {
                                                        {MarketType::A, "A"},
                                                        {MarketType::L, "L"},
                                                        {MarketType::O, "O"},
                                                        {MarketType::R, "R"},
                                                        {MarketType::NOT_APPLICABLE, "NOT_APPLICABLE"},
                                                    });
#endif
