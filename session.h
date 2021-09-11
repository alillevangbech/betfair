#ifndef SESSION_H
#define SESSION_H

#include <string>
#include <memory>
#include <vector>
#include "./acc_enum_fwd.h"
#include "./acc_type_fwd.h"


enum class statusCode
{
	UNKNOWN = 0,
	VALID = 200,
	ERROR = 404,
};

template <typename T>
class Response
{
	public:
		std::unique_ptr<T> m_bfData;
		std::unique_ptr<bfExceptionResponse> m_bfException;
		statusCode m_statusCode;

		Response() : m_bfData(nullptr), m_bfException(nullptr), m_statusCode(statusCode::UNKNOWN) {};
		~Response(){};
};

class Session
{
	public:
		std::string* m_username;
		std::string* m_password;
		std::string* m_sessionId;
		std::string* m_appName;
		std::string* m_appKey; 


		// keep alive	
		Response<authKeepAlive>* keepAliveRequest(/*const std::string& appKey, const std::string& sessionId*/);

		// Create 2 Application Keys for given user; one 'Delayed and the other 'Live'. You must apply to have your 'Live' App Key activated.	 
		Response<DeveloperApp>* createDeveloperAppKeys (/* const std::string& appName */);

		// Get all application keys owned by the given developer/vendor.	 
		Response<std::vector<DeveloperApp>>* getDeveloperAppKeys ();

		// Get available to bet amount.
		Response<AccountFundsResponse>* getAccountFunds ();

		//
		Response<TransferResponse>* transferFunds ( Wallet from, Wallet to, double amount );

		// Returns the details relating your account, including your discount rate and Betfair point balance.
		Response<AccountDetailsResponse>* getAccountDetails ( );

		//	Returns the vendor client id for customer account which is a unique identifier for that customer.
		Response<std::string>* getVendorClientId(); 

		// Used to create new subscription tokens for an application. Returns the newly generated subscription token which can be provided to the end user.
		Response<std::string>* getApplicationSubscriptionToken ( int subscriptionLength );

		// Activates the customers subscription token for an application	 
		Response<Status>* activateApplicationSubscription (const std::string& subscriptionToken);

		// Cancel the subscription token. The customers subscription will no longer be active once cancelled. 
		Response<Status>* cancelApplicationSubscription (const std::string& subscriptionToken ); 

		// Update an application subscription with a new expiry date. 
		Response<std::string>* updateApplicationSubscription (const std::string& vendorClientId, int subscriptionLength );

		// Returns a list of subscription tokens for an application based on the subscription status passed in the request.
		Response<std::vector<ApplicationSubscription>>* listApplicationSubscriptionTokens (SubscriptionStatus subscriptionStatus );

		// List of subscription tokens associated with the account. 
		Response<std::vector<AccountSubscription>>* listAccountSubscriptionTokens ( );

		// Returns a list of subscriptions tokens that have been associated with the customers account. 
		Response<std::vector<SubscriptionHistory>>* getApplicationSubscriptionHistory (const std::string& vendorClientId );

		// Get account statement - provides full audit trail of money moving to and from your account.	Not available via the Vendor Web API.
		Response<AccountStatementReport>* getAccountStatement (const std::string& locale, int fromRecord, int recordCount, const TimeRange& itemDateRange, IncludeItem includeItem, Wallet wallet );

		// Returns a list of currency rates based on given currency. 	 	 	 
		Response<std::vector<CurrencyRate>>* listCurrencyRates (const std::string& fromCurrency );

		// Generate web vendor session based on a standard session identifiable by auth code, vendor secret and app key.
		Response<VendorAccessTokenInfo>* token (const std::string& client_id, GrantType grant_type, const std::string& code, const std::string& client_secret, const std::string& refresh_token );

		// Return details about a vendor from its identifier. Response includes Vendor Name and URL	 	 	 
		Response<VendorDetails>* getVendorDetails (const std::string& vendorId );

		// Remove the link between an account and a vendor web app. This will remove the refreshToken for this user-vendor pair subscription.	 	 	 
		Response<Status>* revokeAccessToWebApp ( long vendorId );

		// Retrieve all vendors applications currently subscribed to by the user making the request	 	 	 
		Response<std::vector<VendorDetails>>* listAuthorizedWebApps ( );

		// Return whether an account has authorised a web app.	 	 	 
		Response<bool>* isAccountSubscribedToWebApp (const std::string& vendorId );

		// Return relation between a list of users and an affiliate.
		Response<std::vector<AffiliateRelation>>* getAffiliateRelation (const std::vector<std::string>& vendorClientIds );

};

#endif
