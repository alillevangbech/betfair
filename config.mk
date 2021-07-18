
CPRINC = /usr/include/cpr/
CPRLIB = /usr/lib/libcpr.so

CPPFLAGS = -I$(CPRINC) -D_POSIX_C_SOURCE=200809L
CFLAGS   = -std=c++17 -pedantic -Wall -Wextra -Os

LDFLAGS  = -L$(CPRLIB) -s
LDLIBS   = -lcpr

CC = g++
