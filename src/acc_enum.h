#ifndef ACC_ENUM_H
#define ACC_ENUM_H

enum class AffiliateRelationStatus
{
    CEMPTY,
// Vendor client ID valid but not affiliated  
    NOT_AFFILIATED,
// Vendor client ID valid and affiliated     
    AFFILIATED,
// Provided vendor client ID is not valid    
    INVALID_USER,
};

enum class TokenType
{
    CEMPTY,
// Token type used for Vendor Web API interactions for making requests on a customers behalf.    
    BEARER,
};

enum class GrantType
{
    CEMPTY,
// A token that can be used to create a new access token when using the Vendor Web API    
    REFRESH_TOKEN,
// Returned via the Vendor Web API token request.     
    AUTHORIZATION_CODE,
};

enum class WinLose
{
    CEMPTY,
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

enum class IncludeItem
{
    CEMPTY,
// Include all items
    ALL,
// Include payments only
    DEPOSITS_WITHDRAWALS,
// Include exchange bets only
    EXCHANGE,
// Include poker transactions only
    POKER_ROOM,
};

enum class Wallet
{
    CEMPTY,
// The Global Exchange wallet
    UK,
};

enum class ItemClass
{
    CEMPTY,
// Statement item not mapped to a specific class. All values will be concatenated into a single key/value pair. The key will be 'unknownStatementItem' and the value will be a comma separated string. Please note: This is used to represent commission payment items.
    UNKNOWN,
};

enum class Status
{
    CEMPTY,
// Sucess status
    SUCCESS,
};

enum class SubscriptionStatus
{
    CEMPTY,
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

// LOGIN, KEEP_ALIVE, LOGOUT

enum class authStatus
{
    CEMPTY,
    SUCCESS,
    FAIL,
};

enum class authError
{
    CEMPTY,
    INPUT_VALIDATION_ERROR,
    INTERNAL_ERROR,
    NO_SESSION,
};

// BETTING API
enum class MarketType
{
    CEMPTY,
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


#endif
