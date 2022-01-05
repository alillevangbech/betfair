#include <algorithm>
#include <memory>
#include <string>
#include <iostream>

#include <nlohmann/json_fwd.hpp>

#include "acc_type.h"
#include "response.h"
#include "session.h"
#include "json.h"
#include "util.h"

int main()
{
	Session session = Session();
	/* read from user_config file or something */
	session.m_sessionId = new std::string("xx");
	session.m_appKey = new std::string("xx");
	session.m_appName = new std::string("xx");
	session.m_username = new std::string("xx@yy.com");
	session.m_password = new std::string("xx");
	
	auto rep = std::unique_ptr<Response<authKeepAlive>>(session.keepAliveRequest());

	if (rep->m_statusCode == statusCode::VALID)
	{
		nlohmann::json j = *rep->m_bfData;
		std::cout << j.dump() << std::endl;
	}
	else
	{
		nlohmann::json j = *rep->m_bfException;
		std::cout << j.dump() << std::endl;
	}

	return 0;
}

