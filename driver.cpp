#include <string>
#include <iostream>
#include "session.h"

int main()
{
	Session session = Session();
	session.m_sessionId = new std::string("fgJduBl0mZ967FZNjhNHdBgAwa+Q+yVt/b9BE3dSs4s=");
	session.m_appKey = new std::string("VcwjIeTG67VJeQTZ");
	session.m_appName = new std::string("BetfairAnalytics");
	session.m_username = new std::string("alexanderlillevangbech@gmail.com");
	session.m_password = new std::string("Khjiyu867");

	std::cout << "Hello world" << std::endl;
}

