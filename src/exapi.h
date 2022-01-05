
/* 
 * A call will consist of the proper arguments and the following:
 * - Pointer to 'exapi_statuscode' with the proper type;
 * - Pointer to 'exapi_errormessage' with the proper type and no preallocated memory.
 * - Pointer to 'exapi_config' wth the proper type;
 */

struct exapi_config {
	char* baseurl;
	char* sessionId;
	char* appKey;
	char* appName;
	char* username;
	char* password;
};

enum exapi_statuscode
{
	exapi_NONE = -1,
	exapi_UNKNOWN = 0,
	exapi_VALID = 200,
	exapi_ERROR = 404,
};


authKeepAlive keepAliveRequest(const std::string& appKey, const std::string& sessionId);

// Create 2 Application Keys for given user; one 'Delayed and the other 'Live'. You must apply to have your 'Live' App Key activated.	 
DeveloperApp createDeveloperAppKeys (const std::string& appName);

// Get all application keys owned by the given developer/vendor.	 
std::vector<DeveloperApp> getDeveloperAppKeys ();

// Get available to bet amount.
AccountFundsResponse getAccountFunds ();

//
TransferResponse transferFunds ( Wallet from, Wallet to, double amount );

// Returns the details relating your account, including your discount rate and Betfair point balance.
AccountDetailsResponse getAccountDetails ( );

//	Returns the vendor client id for customer account which is a unique identifier for that customer.
std::string getVendorClientId(); 

// Used to create new subscription tokens for an application. Returns the newly generated subscription token which can be provided to the end user.
std::string getApplicationSubscriptionToken ( int subscriptionLength );

// Activates the customers subscription token for an application	 
Status activateApplicationSubscription (const std::string& subscriptionToken);

// Cancel the subscription token. The customers subscription will no longer be active once cancelled. 
Status cancelApplicationSubscription (const std::string& subscriptionToken ); 

// Update an application subscription with a new expiry date. 
std::string updateApplicationSubscription (const std::string& vendorClientId, int subscriptionLength );

// Returns a list of subscription tokens for an application based on the subscription status passed in the request.
std::vector<ApplicationSubscription> listApplicationSubscriptionTokens (SubscriptionStatus subscriptionStatus );

// List of subscription tokens associated with the account. 
std::vector<AccountSubscription> listAccountSubscriptionTokens ( );

// Returns a list of subscriptions tokens that have been associated with the customers account. 
std::vector<SubscriptionHistory> getApplicationSubscriptionHistory (const std::string& vendorClientId );

// Get account statement - provides full audit trail of money moving to and from your account.	Not available via the Vendor Web API.
AccountStatementReport getAccountStatement (const std::string& locale, int fromRecord, int recordCount, const TimeRange& itemDateRange, IncludeItem includeItem, Wallet wallet );

// Returns a list of currency rates based on given currency. 	 	 	 
std::vector<CurrencyRate> listCurrencyRates (const std::string& fromCurrency );

// Generate web vendor session based on a standard session identifiable by auth code, vendor secret and app key.
VendorAccessTokenInfo token (const std::string& client_id, GrantType grant_type, const std::string& code, const std::string& client_secret, const std::string& refresh_token );

// Return details about a vendor from its identifier. Response includes Vendor Name and URL	 	 	 
VendorDetails getVendorDetails (const std::string& vendorId );

// Remove the link between an account and a vendor web app. This will remove the refreshToken for this user-vendor pair subscription.	 	 	 
Status revokeAccessToWebApp ( long vendorId );

// Retrieve all vendors applications currently subscribed to by the user making the request	 	 	 
std::vector<VendorDetails> listAuthorizedWebApps ( );

// Return whether an account has authorised a web app.	 	 	 
bool isAccountSubscribedToWebApp (const std::string& vendorId );

// Return relation between a list of users and an affiliate.
std::vector<AffiliateRelation> getAffiliateRelation (const std::vector<std::string>& vendorClientIds );

