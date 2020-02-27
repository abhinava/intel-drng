# Intel Digital Random Number Generator (DRNG) Utility
### A simple (fun) project that illustrates the use of Intel's DRNG capabilities for random number and random seed generation.

Minimal x86/x86_64 assembly code to invoke the RDRAND/RDSEED instructions from C/C++ source. **_There is a single header file (that needs to be included) and a couple of ASM (.S) files (which actually implement the routines that invoke the `RDSEED` and `RDRAND` instructions._**. Relies on the **`CPUID`** instruction to determine whether the processor supports these capabilities.

Given that these instructions don't require any Ring 0 privileges, they can be invoked from user space. Also, they are _container friendly_; Any applications running inside a Docker/LXC container can invoke these DRNG instructions.

This library is also usable in Linux kernel modules (LKM). See the instructions [below](#use-in-linux-kernel-modules).

We have provided a few simple C and C++ test programs to show the usage. To build these tests, follow the instructions below. To be able to build both x86 and x86_64, appropriate compiler toolchains need to be installed (outside the scope of this manual):

```bash
# Make all (x86 and x86_64 targets)
user@host:/some/dir/git/intel-drng$ make

# Make only x86/x86_64 targets
user@host:/some/dir/git/intel-drng$ make x86
user@host:/some/dir/git/intel-drng$ make x86_64

# To use clang compilers
user@host:/some/dir/git/intel-drng$ make CC=clang CXX=clang++

# To use gcc C compiler and clang C++ compiler
user@host:/some/dir/git/intel-drng$ make CC=gcc CXX=clang++

# To run the generated 64-bit C binary
user@host:/some/dir/git/intel-drng$ ./test_c_random_64

# To run the generated 32-bit C binary
user@host:/some/dir/git/intel-drng$ ./test_c_random_32

# To run the generated 64-bit C++ binary
user@host:/some/dir/git/intel-drng$ ./test_cpp_random_64

# To run the generated 32-bit C++ binary
user@host:/some/dir/git/intel-drng$ ./test_cpp_random_32
```

### Use in Linux Kernel Modules

This RDRAND/RDSEED library can also be used within the kernel in case true random numbers or seeds are needed in kernel space (such as in drivers or Linux kernel modules (LKM)). The same ASM source as well as the header files are usable. In case of LKMs, ensure the Kbuild is setup correctly to have the ASM source and header files be available for building. **_We assume that appropriate kernel headers and build tools are installed_** (see [this](https://kernelnewbies.org/KernelHeaders) and [this](https://www.kernel.org/doc/Documentation/kbuild/modules.txt) for some references. Refer to your Linux distribution's guide on how to install kernel header files.)

```
# Go to the 'lkm-1' directory
user@host:/some/dir/git/intel-drng$ cd test/lkm-1

# Build the example LKM. Notice that the 'MODULE_HOME' is set to the base of the 'intel-drng' project directory
user@host:/some/dir/git/intel-drng/test/lkm-1$ make MODULE_HOME=/some/dir/git/intel-drng

# The generated LKM is 'intel-drng.ko'. Load the module.
user@host:/some/dir/git/intel-drng/test/lkm-1$ sudo insmod ./intel-drng.ko

# Observe the kernel log output
user@host:/some/dir/git/intel-drng/test/lkm-1$ dmesg
...
...
[10573524.704585] Loading Intel DRNG Accessor Module
[10573524.704587] 64-bit Random Number: 2181635107122498510
[10573524.704587] 32-bit Random Number: 2218904060
[10573524.704588] 16-bit Random Number: 30025

# Unload the kernel module
user@host:/some/dir/git/intel-drng/test/lkm-1$ sudo rmmod intel-drng.ko

# Observe the kernel log after unloading
user@host:/some/dir/git/intel-drng/test/lkm-1$ dmesg
...
...
[10573670.742170] Unloading Intel DRNG Accessor Module... Goodbye!
[10573670.742173] 64-bit Random Number: 11810063415406240295
[10573670.742175] 32-bit Random Number: 3370028278
[10573670.742177] 16-bit Random Number: 45916

# Cleanup
user@host:/some/dir/git/intel-drng/test/lkm-1$ make clean
```
---
**Example (test) applications tested with the following compiler(s)**:
 * Linux
     * C
         * `(gcc -v) gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1) - Target: x86_64-linux-gnu`
         * `(clang -v) clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final) - Target: x86_64-pc-linux-gnu`
     * C++
         * `(g++ -v) gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1) - Target: x86_64-linux-gnu`
         * `(clang++ -v) clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final) - Target: x86_64-pc-linux-gnu`
 * OS X
     * C
         * `(gcc -v) Apple clang version 11.0.0 (clang-1100.0.33.17) - Target: x86_64-apple-darwin19.3.0`

---
**References:**
  * [Intel® Digital Random Number Generator (DRNG) Software Implementation Guide](https://software.intel.com/en-us/articles/intel-digital-random-number-generator-drng-software-implementation-guide "Intel DRNG")
  * [The Difference Between RDRAND and RDSEED](https://software.intel.com/en-us/blogs/2012/11/17/the-difference-between-rdrand-and-rdseed "RDRAND and RDSEED")
---
> _Keywords: Intel, DRBG, DRNG, RDRAND, RDSEED, random number, TRNG, CSPRNG_

---
**Abhinava Sadasivarao** (abhinava.sadasivarao+github@gmail.com)
