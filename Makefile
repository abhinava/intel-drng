CC=gcc
CXX=g++
CFLAGS=-g
CXXFLAGS=-g
INCLUDE=-I ./include
ARCH=
DEPS=./include/intel_drng.h ./src/*.S
C_BIN_32=test_c_random_32
C_BIN_64=test_c_random_64
CPP_BIN_32=test_cpp_random_32
CPP_BIN_64=test_cpp_random_64

BINS=$(C_BIN_32) $(C_BIN_64) $(CPP_BIN_32) $(CPP_BIN_64)

all: x86 x86_64 

x86: x86_c x86_cpp

x86_64: x86_64_c x86_64_cpp

x86_c: $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(C_BIN_32) ./src/random_32.S ./test/test_random.c -m32

x86_64_c: $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(C_BIN_64) ./src/random_64.S ./test/test_random.c -m64

x86_cpp: $(DEPS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(CPP_BIN_32) ./src/random_32.S ./test/test_random.cpp -m32

x86_64_cpp: $(DEPS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(CPP_BIN_64) ./src/random_64.S ./test/test_random.cpp -m64


clean:
	rm -f *.o $(BINS) 
