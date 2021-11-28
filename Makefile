.POSIX:

include config.mk

PRG_NAME = exApi

CFLAGS   = -std=c++17 -pedantic -Wall -Wextra -Os -D_POSIX_C_SOURCE=200809L
CFLAGS	 += -Ilib/cpr/include -Ilib/json/include
LDFLAGS  = cpr-1.7.0/build/lib/	 -lm

CC = g++

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

run: build
	./$(PRG_NAME)

build: $(OBJ)
	$(CC) -o ${PRG_NAME} $^ $(LDFLAGS)

.cpp.o:
	$(CC) -o $@ -c $< $(CFLAGS)

libs:
	cd lib/cpr && mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=False -DCPR_BUILD_TESTS=OFF -DCPR_FORCE_USE_SYSTEM_CURL=OFF ../ && cmake --build . && cp -r cpr_generated_includes/cpr/* include/cpr/
	
clean:
	rm -rf $(OBJ) $(PRG_NAME) driver.o
