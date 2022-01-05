.POSIX:

include config.mk

PRG_NAME = exApi

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

all: build run

run: build
	./$(PRG_NAME)

build: $(OBJ) $(HEAD)
	$(CC) -o ${PRG_NAME} $^ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -o $@ -c $< 

libs:
	cd lib/cpr && mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=False -DCPR_BUILD_TESTS=OFF -DCPR_FORCE_USE_SYSTEM_CURL=OFF -DCMAKE_USE_OPENSSL=ON ../ && cmake --build . && cp -r cpr_generated_includes/cpr/* ../include/cpr/
	
clean:
	rm -rf $(OBJ) $(OBJ:.o=.d) $(PRG_NAME) driver.o

-include $(OBJ:.o=.d)
