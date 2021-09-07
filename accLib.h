 #ifndef ACC_LIB_H
 #define ACC_LIB_H
 
 #include <string>
 #include <json.hpp>
 
 template<typename T>
 std::string sEnum(const T e)
 {
     nlohmann::json j = e;
     std::string res = j.dump();
     return res.substr(1,res.size() - 2);
 };
 
 #endif
