# Intel Digital Random Number Generator (DRNG) Utility
### A simple (and naive) project that uses Intel's DRNG capabilities for random number generation and random seed generation.

Minimal x86 assembly code to invoke the RDRAND/RDSEED instructions.

> Keywords: Intel, DRBG, DRNG, RDRAND, RDSEED, random number

> **Compiler(s)**:
>  * `gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1) - Target: x86_64-linux-gnu`
>  * `clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final) - Target: x86_64-pc-linux-gnu`

To build, follow the instructions below. To be able to build both x86 and x86_64, correct host and compiler toolchains need to be installed (outside the scope of this manual):

```bash
# Make all (x86 and x86_64 targets)
[user@host:/some/dir/git/intel-drng] make

# Make only x86/x86_64 targets
user@host:/some/dir/git/intel-drng$ make x86
user@host:/some/dir/git/intel-drng$ make x86_64

# To use clang
user@host:/some/dir/git/intel-drng$ make CC=clang

# To run the generated 64-bit binary
user@host:/some/dir/git/intel-drng$ ./test_random_64

# To run the generated 32-bit binary
user@host:/some/dir/git/intel-drng$ ./test_random_32
```

**References:**
  * [Intel® Digital Random Number Generator (DRNG) Software Implementation Guide](https://software.intel.com/en-us/articles/intel-digital-random-number-generator-drng-software-implementation-guide "Intel DRNG")
  * [The Difference Between RDRAND and RDSEED](https://software.intel.com/en-us/blogs/2012/11/17/the-difference-between-rdrand-and-rdseed "RDRAND and RDSEED")

---
**Abhinava Sadasivarao** (abhinava.sadasivarao+github@gmail.com)
