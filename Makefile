.POSIX:

include config.mk

SRC_DIR = .

SRC = ${SRC_DIR}/main.cpp
#      ${SRC_DIR}/main.c \
#      ${SRC_DIR}/base64.c \
#      ${SRC_DIR}/md5.c \
#      ${SRC_DIR}/lib.c

OBJ = ${SRC:.cpp=.o}

PRG_NAME = exApi

# creates executable
all: ${OBJ}
	${CC} -o ${PRG_NAME} $(LDFLAGS) ${OBJ} $(LDLIBS)

# creates .o files from .c files with same names
${SRC_DIR}/.c.o:
	${CC} -c $(CPPFLAGS) $(CFLAGS) $<

run: all
	./${PRG_NAME}

clean: 
	rm -rf ${OBJ} ${PRG_NAME}

.PHONY: all clean
