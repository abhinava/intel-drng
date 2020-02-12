# Intel DRNG Utility
### A simple (and naive) project that uses Intel's DRNG capabilities for random number generation and random seed generation.

> Keywords: Intel, DRBG, DRNG, RDRAND, RDSEED, random number

> Compilers: `GCC 7.4.0 (64-bit and 32-bit) on Ubuntu 18.04`

To build, follow the instructions below:

```bash
[user@host:~] make
[user@host:~] make x86
[user@host:~] make x86_64
```

**References:**
  * [Intel® Digital Random Number Generator (DRNG) Software Implementation Guide](https://software.intel.com/en-us/articles/intel-digital-random-number-generator-drng-software-implementation-guide "Intel DRNG")
  * [The Difference Between RDRAND and RDSEED](https://software.intel.com/en-us/blogs/2012/11/17/the-difference-between-rdrand-and-rdseed "RDRAND and RDSEED")

---
**Abhinava Sadasivarao** (abhinava.sadasivarao+github@gmail.com)
