.POSIX:

include config.mk

# SRC_DIR  = .

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

PRG_NAME = exApi

all: exApi

.cpp.o:
	$(CC) $(STCFLAGS) -c $<

main.o: args.h

$(OBJ): config.mk

exApi: $(OBJ)
	$(CC) -o $@ $(OBJ) $(STLDFLAGS)

run: exApi
	./${PRG_NAME}

clean: 
	rm -rf ${OBJ} ${PRG_NAME}

.PHONY: all clean run

