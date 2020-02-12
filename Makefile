CC=gcc
CFLAGS=-g -I ./include
ARCH=
DEPS=./include/intel_random.h ./src/*.S
BIN_32=test_random_32
BIN_64=test_random_64

all: x86 x86_64 

x86: $(DEPS)
	$(CC) -o $(BIN_32) ./src/random_32.S ./test/test_random.c -m32 $(CFLAGS)

x86_64: $(DEPS)
	$(CC) -o $(BIN_64) ./src/random_64.S ./test/test_random.c -m64 $(CFLAGS)

clean:
	rm -f *.o $(BIN_64) $(BIN_32) 
