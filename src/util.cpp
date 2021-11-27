#include <string>
#include "util.h"
#include "acc_type.h"
#include "acc_enum.h"

bool empty(const bfAccountAPINGException& b)
{ 
	return b.requestUUID.empty() && b.errorCode.empty() && b.errorDetails.empty();
}

bool empty(const bfDetail& b) 
{ 
	return b.exceptionname.empty() && empty(b.AccountAPINGException);
}

bool empty(const bfExceptionResponse& b)
{ 
	return empty(b.detail) && b.faultcode.empty() && b.faultstring.empty();
}

void setEmpty(bfAccountAPINGException& b) 
{ 
	b.requestUUID = std::string();
	b.errorCode = std::string();
	b.errorDetails = std::string();
}

void setEmpty(bfDetail& b) 
{ 
	b.exceptionname = std::string();
	setEmpty(b.AccountAPINGException);
}
