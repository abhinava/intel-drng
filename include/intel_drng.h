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

// This block is required to allow C++ compatibility.
// See the corresponding scope closing at the end of the file.
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __KERNEL__ // Needed for kernel modules
#include <linux/types.h>
// Use Linux kernel's unsigned integer types
#define U16 u16
#define U32 u32
#define BOOL u8
#define TRUE 1
#define FALSE 0
#else             // Userspace applications
// Use standard C unsigned integer types
#define U16 uint16_t
#define U32 uint32_t 
#define BOOL bool
#define TRUE true 
#define FALSE false
#include <stdint.h>
#include <stdbool.h>
#endif

#ifdef __x86_64__  // If the host is 64-bit capable
#ifdef __KERNEL__
// Use Linux kernel's unsigned integer types
#define U64 u64
#else
// Use standard C unsigned integer types
#define U64 uint64_t
#endif

extern U64 _random_64(void);

// Declaration
U64 random_64(void);

// Definition
inline U64 random_64(void) 
{
    return _random_64();
}
#endif // __x86_64__

extern U32 _random_32(void);
extern U16 _random_16(void);

extern uint8_t _rdrand_capability(void);
extern uint8_t _rdseed_capability(void);

/*
 * Declarations
 */
U32 random_32(void);
U16 random_16(void);
BOOL is_rdrand_available(void);
BOOL is_rdseed_available(void);

/*
 * Definitions
 */
inline U32 random_32(void) 
{
    return _random_32();
}

inline U16 random_16(void) 
{
    return _random_16();
}

/**
 * Returns True if RDRAND capability is available.
 * Returns False otherwise.
 */
inline BOOL is_rdrand_available(void)
{
    if (_rdrand_capability()) {
        return TRUE;
    }

    return FALSE;
}

/**
 * Returns True if RDSEED capability is available.
 * Returns False otherwise.
 */
inline BOOL is_rdseed_available(void)
{
    if (_rdseed_capability()) {
        return TRUE;
    }

    return FALSE;
}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _INTEL_RANDOM_H_
