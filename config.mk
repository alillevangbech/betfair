
CFLAGS   = -std=c++17 -pedantic -Wall -Wextra -Os -D_POSIX_C_SOURCE=200809L
CFLAGS	 += -I./lib/cpr/include -I./lib/json/include

LDFLAGS  = ./lib/cpr/build/lib/libcpr.so -lcpr

CC = g++
