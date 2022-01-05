#ifndef RESPONSE_H
#define RESPONSE_H

#include <memory>
#include "./acc_enum.h"
#include "./acc_type.h"

enum statusCode
{
	UNKNOWN = 0,
	VALID = 200,
	ERROR = 404,
};

template <typename T>
class Response
{
	public:
		T* m_bfData;
		bfExceptionResponse* m_bfException;
		statusCode m_statusCode;

		Response() : m_bfData(new T()),
					 m_bfException(new bfExceptionResponse()),
					 m_statusCode(statusCode::UNKNOWN) {};
		~Response(){};
};


#endif
