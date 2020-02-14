# Intel Digital Random Number Generator (DRNG) Utility
### A simple (fun) project that illustrates the use of Intel's DRNG capabilities for random number generation and random seed generation.

Minimal x86/x86_64 assembly code to invoke the RDRAND/RDSEED instructions from C/C++ source. **_There is a single header file (that needs to be included) and a couple of ASM (.S) files (which actually implement the routines that invoke the `RDSEED` and `RDRAND` instructions._**

**Tested with the following compiler(s)**:
 * Linux
     * C
         * `gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1) - Target: x86_64-linux-gnu`
         * `clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final) - Target: x86_64-pc-linux-gnu`
     * C++
         * `(g++) gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1) - Target: x86_64-linux-gnu`
         * `clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final) - Target: x86_64-pc-linux-gnu`
 * OS X
     * C
         * `Apple clang version 11.0.0 (clang-1100.0.33.17) - Target: x86_64-apple-darwin19.3.0`

We have provided a few simple C and C++ test programs to show the usage. To build these tests, follow the instructions below. To be able to build both x86 and x86_64, appropriate compiler toolchains need to be installed (outside the scope of this manual):

```bash
# Make all (x86 and x86_64 targets)
[user@host:/some/dir/git/intel-drng] make

# Make only x86/x86_64 targets
user@host:/some/dir/git/intel-drng$ make x86
user@host:/some/dir/git/intel-drng$ make x86_64

# To use `clang` compilers
user@host:/some/dir/git/intel-drng$ make CC=clang CXX=clang++

# To use `gcc` C compiler and `clang` C++ compiler
user@host:/some/dir/git/intel-drng$ make CC=gcc CXX=clang++

# To run the generated 64-bit C binary
user@host:/some/dir/git/intel-drng$ ./test_c_random_64

# To run the generated 32-bit C binary
user@host:/some/dir/git/intel-drng$ ./test_c_random_32

# To run the generated 64-bit C++ binary
user@host:/some/dir/git/intel-drng$ ./test_cpp_random_64

# To run the generated 32-bit C binary
user@host:/some/dir/git/intel-drng$ ./test_cpp_random_32
```

**References:**
  * [Intel® Digital Random Number Generator (DRNG) Software Implementation Guide](https://software.intel.com/en-us/articles/intel-digital-random-number-generator-drng-software-implementation-guide "Intel DRNG")
  * [The Difference Between RDRAND and RDSEED](https://software.intel.com/en-us/blogs/2012/11/17/the-difference-between-rdrand-and-rdseed "RDRAND and RDSEED")

> _Keywords: Intel, DRBG, DRNG, RDRAND, RDSEED, random number, TRNG, CSPRNG_

---
**Abhinava Sadasivarao** (abhinava.sadasivarao+github@gmail.com)
