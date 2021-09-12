.POSIX:

include config.mk

PRG_NAME = exApi

SRC = json.cpp session.cpp util.cpp # driver.cpp

# Headers: acc_type.h acc_type_fwd.h
# Headers: acc_enum.h acc_enum_fwd.h
# Headers: response.h session.h cpr.h json.h util.h

OBJ = $(SRC:.cpp=.o)

run: build
	./$(PRG_NAME)

build: $(OBJ) driver

driver: driver.o $(OBJ)
	$(CC) -o ${PRG_NAME} $(LDFLAGS) $? $(LDLIBS) $(CPPFLAGS)

driver.o: driver.cpp

json.o: json.cpp json.h util.h acc_enum.h acc_enum.h
util.o: util.cpp util.h acc_enum.h acc_enum.h
session.o: session.cpp session.h response.h util.h json.h cpr.h

.cpp.o:
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ) $(PRG_NAME) driver.o

# driver.cpp
