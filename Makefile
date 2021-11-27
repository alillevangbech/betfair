.POSIX:

include config.mk

PRG_NAME = exApi

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

run: build
	./$(PRG_NAME)

build: $(OBJ) driver

driver: driver.o $(OBJ)
	$(CC) -o ${PRG_NAME} $(LDFLAGS) $? $(LDLIBS) $(CPPFLAGS)

driver.o: driver.cpp

.cpp.o:
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ) $(PRG_NAME) driver.o

# driver.cpp
