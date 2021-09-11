.POSIX:

include config.mk

PRG_NAME = exApi

SRC = json.cpp session.cpp util.cpp driver.cpp

OBJ = $(SRC:.cpp=.o)

run: build
	./$(PRG_NAME)

build: $(OBJ) driver

driver: driver.o $(OBJ)
	$(CC) -o ${PRG_NAME} $(LDFLAGS) $? $(LDLIBS) $(CPPFLAGS)

json.o: json.cpp json.h acc_type.h acc_enum.h
session.o: session.cpp session.h acc_type.h acc_enum.h
util.o: util.cpp util.h acc_type.h acc_enum.h
driver.o: driver.cpp driver.h

.cpp.o:
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ) $(PRG_NAME) driver.o

# driver.cpp
