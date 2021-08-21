#include </usr/include/nlohmann/json.hpp>
#include <iostream>
#include <string>

enum class authStatus
{
    SUCCESS,
    FAIL,
};
void to_json(nlohmann::json& j, const authStatus& p);
void from_json(const nlohmann::json& j, authStatus p);
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
void to_json(nlohmann::json& j, const authError& p);
void from_json(const nlohmann::json& j, authError p);
NLOHMANN_JSON_SERIALIZE_ENUM(authError,    {
        {authError::INPUT_VALIDATION_ERROR, "INPUT_VALIDATION_ERROR"},
        {authError::INTERNAL_ERROR, "INTERNAL_ERROR"},
        {authError::NO_SESSION, "NO_SESSION"},
        });

struct authKeepAlive
{
    public:
        std::string token;
        std::string product;
        authStatus status;
        authError error;
};
void to_json(nlohmann::json& j, const authKeepAlive& p);
void from_json(const nlohmann::json& j, authKeepAlive& p);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(authKeepAlive, token, product, status, error);

int main()
{
    std::cout << "hello world" << std::endl;
    return 0;
}
