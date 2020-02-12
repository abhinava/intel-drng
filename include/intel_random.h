/**
 *
 * A simple header-file libary that provides APIs to use
 * Intel's Digital Random Number Generator (DRNG) capabilities.
 * 
 * x64/x86_64 assembly routines to generate 64-bit, 32-bit
 * and 16-bit true random numbers and random number seeds
 * using Intel's RDRAND and RDSEED instructions.
 *
 * TODO:
 *   - Provide RDSEED utilities
 *   - Test compiler independence (clang v/s gcc)
 *
 * Reference:
 *  - https://software.intel.com/en-us/articles/intel-digital-random-number-generator-drng-software-implementation-guide
 *  - https://software.intel.com/en-us/blogs/2012/11/17/the-difference-between-rdrand-and-rdseed
 *
 * Abhinava Sadasivarao (abhinava.sadasivarao@gmail.com)
 *
 */

#ifndef _INTEL_RANDOM_H_
#define _INTEL_RANDOM_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __x86_64__
extern uint64_t random_64();
#endif

extern uint32_t random_32();
extern uint16_t random_16();

extern uint8_t rdrand_capability();
extern uint8_t rdseed_capability();

// Declaration
bool is_rdrand_available();
bool is_rdseed_available();

// Definition
/**
 * Returns True if RDRAND capability is available.
 * Returns False otherwise.
 */
inline bool is_rdrand_available()
{
    if (rdrand_capability()) {
        return true;
    }

    return false;
}

/**
 * Returns True if RDSEED capability is available.
 * Returns False otherwise.
 */
inline bool is_rdseed_available()
{
    if (rdseed_capability()) {
        return true;
    }

    return false;
}

#endif // _INTEL_RANDOM_H_
