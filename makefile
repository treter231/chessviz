OBJ = 
CC = gcc
CFLAGS = -Wall -Werror -std=c99

.PHONY: clean open

./bin/doska: ./build/main.o ./build/doska.o ./build/check_pozishion.o bin 
    $(CC) $(CFLAGS) -o ./bin/doska ./build/main.o ./build/doska.o ./build/check_pozishion.o -lm

./build/main.o: ./src/main.c ./src/doska.h build
    $(CC) $(CFLAGS) -o build/main.o -c src/main.c -lm

./build/doska.o: ./src/doska.c ./src/doska.h build
    $(CC) $(CFLAGS) -o ./build/doska.o -c ./src/doska.c -lm

./build/check_pozishion.o: ./src/check_pozishion.c ./src/check_pozishion.h build
    $(CC) $(CFLAGS) -o ./build/check_pozishion.o -c ./src/check_pozishion.c -lm
build:
    mkdir build

bin:
    mkdir bin

clean:
    rm -rf build bin

open:
    ./bin/doska