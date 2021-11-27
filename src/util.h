#ifndef UTIL_H
#define UTIL_H

struct bfAccountAPINGException;
struct bfDetail;
struct bfExceptionResponse;

bool empty(const bfAccountAPINGException& b);
bool empty(const bfDetail& b);
bool empty(const bfExceptionResponse b);
void setEmpty(bfAccountAPINGException& b); 
void setEmpty(bfDetail& b); 
 
#endif
