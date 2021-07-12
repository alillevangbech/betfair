
CPRINC = /usr/include/cpr
CPRLIB = /usr/lib/libcpr.so

# flags
INCS = -I$(CPRINC)
LIBS = -L$(CPRLIB) -lcprlib -s
CFLAGS   = -std=c++17 -pedantic -Wall -Wextra -Os

STCPPFLAGS = -D_XOPEN_SOURCE=600
STCFLAGS = $(INCS) $(STCPPFLAGS) $(CPPFLAGS) $(CFLAGS)
STLDFLAGS = $(LIBS) $(LDFLAGS)

# compiler and linker
CC = g++
