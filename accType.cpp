#include <vector>
#include <map>
#include <nlohmann/json.hpp>
// #include "./accEnum.h"

struct VendorDetails
{
    // URL to be redirected to
    std::string redirectUrl;
    // Vendor name
    std::string vendorName;
    // Internal id of the application
    long appVersionId;
};
NLOHMANN_DEFINE_TYPE_NON_INSTRUSIVE(VendorDetails, redirectUrl, vendorName, appVersionId);
