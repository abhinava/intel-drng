# Intel Digital Random Number Generator (DRNG) Utility
### A simple (and naive) project that uses Intel's DRNG capabilities for random number generation and random seed generation.

Minimal x86 assembly code to invoke the RDRAND/RDSEED instructions.

> Keywords: Intel, DRBG, DRNG, RDRAND, RDSEED, random number

> **Compiler(s)**:
>  * `gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1) - Target: x86_64-linux-gnu`
>  * `clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final) - Target: x86_64-pc-linux-gnu`

To build, follow the instructions below:

```bash
[user@host:~] make
[user@host:~] make x86
[user@host:~] make x86_64

# To use clang
[user@host:~] make CC=clang
```

**References:**
  * [Intel® Digital Random Number Generator (DRNG) Software Implementation Guide](https://software.intel.com/en-us/articles/intel-digital-random-number-generator-drng-software-implementation-guide "Intel DRNG")
  * [The Difference Between RDRAND and RDSEED](https://software.intel.com/en-us/blogs/2012/11/17/the-difference-between-rdrand-and-rdseed "RDRAND and RDSEED")

---
**Abhinava Sadasivarao** (abhinava.sadasivarao+github@gmail.com)
