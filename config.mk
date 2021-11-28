
CFLAGS   = -std=c++17 -pedantic -Wall -Wextra -Os -D_POSIX_C_SOURCE=200809L
CFLAGS	 += -Ilib/cpr/include -Ilib/json/include 
LDFLAGS  = lib/cpr/build/lib/* -lssl -lcrypto -lssh2 -lpthread

CC = g++
