#ifndef RESPONSE_H
#define RESPONSE_H

#include <memory>
#include "./acc_enum_fwd.h"
#include "./acc_type_fwd.h"

enum class statusCode
{
	UNKNOWN = 0,
	VALID = 200,
	ERROR = 404,
};


template <typename T>
class Response
{
	public:
		std::unique_ptr<T> m_bfData;
		std::unique_ptr<bfExceptionResponse> m_bfException;
		statusCode m_statusCode;

		Response() : m_bfData(nullptr), m_bfException(nullptr), m_statusCode(statusCode::UNKNOWN) {};
		~Response(){};
};

#endif
