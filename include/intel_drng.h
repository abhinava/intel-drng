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

// This block is required to allow C++ compatibility.
// See the corresponding scope closing at the end of the file.
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __x86_64__
extern uint64_t _random_64();

// Declaration
uint64_t random_64();

// Definition
inline uint64_t random_64() 
{
    return _random_64();
}
#endif // __x86_64__

extern uint32_t _random_32();
extern uint16_t _random_16();

extern uint8_t _rdrand_capability();
extern uint8_t _rdseed_capability();

/*
 * Declarations
 */
uint32_t random_32();
uint16_t random_16();
bool is_rdrand_available();
bool is_rdseed_available();

/*
 * Definitions
 */
inline uint32_t random_32() 
{
    return _random_32();
}

inline uint16_t random_16() 
{
    return _random_16();
}

/**
 * Returns True if RDRAND capability is available.
 * Returns False otherwise.
 */
inline bool is_rdrand_available()
{
    if (_rdrand_capability()) {
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
    if (_rdseed_capability()) {
        return true;
    }

    return false;
}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _INTEL_RANDOM_H_
