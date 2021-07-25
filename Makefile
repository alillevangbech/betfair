.POSIX:

# TODO:
# Create driver executable which collects all .o files
# Create static library for daemon to link up against.

include config.mk

SRC_DIR = .

SRC = 	${SRC_DIR}/accType.cpp \
    	${SRC_DIR}/accEnum.cpp

#	${SRC_DIR}/driver.cpp

OBJ = ${SRC:.cpp=.o}

${SRC_DIR}/.c.o:
	${CC} -c $(CPPFLAGS) $(CFLAGS) $<

PRG_NAME = exApi


driver.o: ${OBJ}
	${CC} -c $(CPPFLAGS) $(CFLAGS) $<

# creates executable
all: ${OBJ}
	${CC} -o ${PRG_NAME} $(LDFLAGS) ${OBJ} $(LDLIBS)

# creates .o files from .c files with same names

run: all
	./${PRG_NAME}

clean: 
	rm -rf ${OBJ} ${PRG_NAME}

.PHONY: all clean
