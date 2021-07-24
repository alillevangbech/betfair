
CPRINC = /usr/include/cpr
CPRLIB = /usr/lib/libcpr.so

# json || header only
NLOHMANNINC = /usr/include/nlohmann

CPPFLAGS = -I$(CPRINC) -I$(NLOHMANNINC) -D_POSIX_C_SOURCE=200809L
CFLAGS   = -std=c++17 -pedantic -Wall -Wextra -Os

LDFLAGS  = -L$(CPRLIB) -s
LDLIBS   = -lcpr

CC = g++
