.POSIX:

# TODO:
# Create driver executable which collects all .o files | literally what a test program do. lol
#
# Create static library for daemon to link up against.

include config.mk

SRC = 	accType.cpp \
    	accEnum.cpp

OBJ = $(SRC:.cpp=.o)

accType.o: accType.cpp
accEnum.o: accEnum.cpp

# .c.o:
# 	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<







# 	
# 	$(SRC_DIR)/.c.o:
# 		$(CC) -c $(CPPFLAGS) $(CFLAGS) $<
# 	
# 	PRG_NAME = exApi
# 	
# 	driver.o: $(OBJ)
# 		$(CC) -c $(CPPFLAGS) $(CFLAGS) $<
# 	
# 	# creates executable
# 	all: driver.o
# 		$(CC) -o ${PRG_NAME} $(LDFLAGS) driver.o $(LDLIBS)
# 	
# 	# creates .o files from .c files with same names
# 	
# 	run: all
# 		./$(PRG_NAME)
# 	
# 	clean: 
# 		rm -rf $(OBJ) driver.o ${PRG_NAME}
# 	
# 	.PHONY: all clean
