#include <string>
#include <iostream>

int main()
{
	std::cout << "hello world" << std::endl;
}

//
//
//    authKeepAlive keepAliveRequest(const std::string& appKey, const std::string& sessionId)
//    {
//        std::string auth_global_url = "https://identitysso.betfair.com/api/keepAlive";
//        std::string user = "alexanderlillevangbech@gmail.com";
//        std::string pass = "Khjiyu867";
//        cpr::Payload authBody = {{"username",user},{"password",pass}};
//        cpr::Header authHeaders = {
//            {"Content-Type","application/x-www-form-urlencoded"},
//            {"Content-Length", std::to_string(authBody.GetContent(cpr::CurlHolder()).length())},
//            {"Accept", "application/json"},
//            {"X-Application", appKey},
//            {"X-Authentication", sessionId},
//            {"Connection", "keep-alive"},
//        };
//    
//        cpr::Response r = cpr::Post(cpr::Url{auth_global_url},
//                authHeaders,
//                authBody);
//    
//        std::cout << r.text << std::endl;
//        json j = json::parse(r.text);
//        authKeepAlive ret = j;
//    
//        return ret;
//    };
//
//
