.POSIX:

include config.mk

PRG_NAME = exApi

SRC = 	accType.cpp

OBJ = $(SRC:.cpp=.o)

run: build
	./$(PRG_NAME)

build: $(OBJ) driver

driver: driver.o $(OBJ)
	$(CC) -o ${PRG_NAME} $(LDFLAGS) $? $(LDLIBS) $(CPPFLAGS)

accType.o: accType.cpp accType.h accEnum.h
driver.o: driver.cpp driver.h accLib.h

.cpp.o:
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ) $(PRG_NAME) driver.o

# driver.cpp
