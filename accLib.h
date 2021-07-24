#include <string>
#include <map>
#include <vector>
#include "./accType.h"

// Create 2 Application Keys for given user; one 'Delayed and the other 'Live'. You must apply to have your 'Live' App Key activated.	 
DeveloperApp createDeveloperAppKeys (std::string appName );

// Get all application keys owned by the given developer/vendor.	 
std::vector<DeveloperApp> getDeveloperAppKeys ( );

// Get available to bet amount.
AccountFundsResponse getAccountFunds ();

// Transfer funds
TransferResponse transferFunds ( Wallet from, Wallet to, double amount );

// Returns the details relating your account, including your discount rate and Betfair point balance.
AccountDetailsResponse getAccountDetails ( );

//	Returns the vendor client id for customer account which is a unique identifier for that customer.
std::string getVendorClientId ( ); 

// Used to create new subscription tokens for an application. Returns the newly generated subscription token which can be provided to the end user.
std::string getApplicationSubscriptionToken ( int subscriptionLength );

// Activates the customers subscription token for an application	 
Status activateApplicationSubscription ( std::string subscriptionToken );

// Cancel the subscription token. The customers subscription will no longer be active once cancelled. 
Status cancelApplicationSubscription ( std::string subscriptionToken ); 

// Update an application subscription with a new expiry date. 
std::string updateApplicationSubscription ( std::string vendorClientId, int subscriptionLength );

// Returns a list of subscription tokens for an application based on the subscription status passed in the request.
std::vector<ApplicationSubscription> listApplicationSubscriptionTokens ( SubscriptionStatus subscriptionStatus );

// std::vector of subscription tokens associated with the account. 
std::vector<AccountSubscription> listAccountSubscriptionTokens ( );

// Returns a list of subscriptions tokens that have been associated with the customers account. 
std::vector<SubscriptionHistory> getApplicationSubscriptionHistory ( std::string vendorClientId );

// Get account statement - provides full audit trail of money moving to and from your account.	Not available via the Vendor Web API.
AccountStatementReport getAccountStatement ( std::string locale, int fromRecord, int recordCount, TimeRange itemDateRange, IncludeItem includeItem, Wallet wallet );

// Returns a list of currency rates based on given currency. 	 	 	 
std::vector<CurrencyRate> listCurrencyRates ( std::string fromCurrency );

// Generate web vendor session based on a standard session identifiable by auth code, vendor secret and app key.
VendorAccessTokenInfo token ( std::string client_id, GrantType grant_type, std::string code, std::string client_secret, std::string refresh_token );

// Return details about a vendor from its identifier. Response includes Vendor Name and URL	 	 	 
VendorDetails getVendorDetails ( std::string vendorId );

// Remove the link between an account and a vendor web app. This will remove the refreshToken for this user-vendor pair subscription.	 	 	 
Status revokeAccessToWebApp ( long vendorId );

// Retrieve all vendors applications currently subscribed to by the user making the request	 	 	 
std::vector<VendorDetails> listAuthorizedWebApps ( );

// Return whether an account has authorised a web app.	 	 	 
bool isAccountSubscribedToWebApp ( std::string vendorId );

// Return relation between a list of users and an affiliate.
std::vector<AffiliateRelation> getAffiliateRelation ( std::vector<std::string> vendorClientIds );
