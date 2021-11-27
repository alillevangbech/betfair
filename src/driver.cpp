#include <algorithm>
#include <memory>
#include <string>
#include <iostream>
#include <memory.h>
#include "acc_type.h"
#include "json_fwd.hpp"
#include "response.h"
#include "session.h"
#include "json.h"
#include "util.h"

int main()
{
	Session session = Session();
	session.m_sessionId = new std::string("Mg3jIqYqBSZMkUEdj19hgdHaCyL46i0KpKyHWHNBz+Q=");
	session.m_appKey = new std::string("VcwjIeTG67VJeQTZ");
	session.m_appName = new std::string("BetfairAnalytics");
	session.m_username = new std::string("alexanderlillevangbech@gmail.com");
	session.m_password = new std::string("Khjiyu867");
	
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
}

