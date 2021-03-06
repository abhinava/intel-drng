/**
 * Simple x86_64 assembly routines to retrieve 64-bit, 32-bit
 * and 16-bit true random numbers and random number seeds 
 * using Intel's DRNG instructions.
 *
 * TODO:
 *   - Provide RDSEED instruction based generation of seeds
 *
 * Reference:
 *  - https://software.intel.com/en-us/articles/intel-digital-random-number-generator-drng-software-implementation-guide
 *  - https://software.intel.com/en-us/blogs/2012/11/17/the-difference-between-rdrand-and-rdseed
 *
 * Abhinava Sadasivarao (abhinava.sadasivarao@gmail.com)
 *
 */

.global _random_64
.global _random_32
.global _random_16
.global _rdrand_capability
.global _rdseed_capability

/*
 * Returns 1 if RDRAND capability is available; 0 otherwise
 */
_rdrand_capability:
   push  %rbp
   movq  %rsp, %rbp

   mov   %rbx, %rsi   # Save RBX since CPUID clobbers RBX

   movq  $1,   %rax
   cpuid

/*
    movl  $1,   %r8d
    shl   $30,  %r8d   # 30th bit of ECX for RDRAND
*/
   mov   $0x40000000, %r8d # 0x40000000 is 30th bit set
   test  %ecx, %r8d
   jz    no_rdrand    # RDRAND not supported

   movq  $1,   %rax
   jmp   done_rdrand

no_rdrand:
   movq  $0,   %rax

done_rdrand:
   mov  %rsi, %rbx   # Restore RBX
   popq %rbp
   retq

/*
 * Returns 1 if RDSEED capability is available; 0 otherwise
 */
_rdseed_capability:
   push  %rbp
   mov   %rsp, %rbp

   mov   %rbx, %rsi   # Save RBX since CPUID clobbers RBX

   mov   $7,   %rax   # EAX=7 & ECX=0 to get Extended Features
   mov   $0,   %rcx
   cpuid

/*
   mov   $1,   %r8d
   shl   $18,  %r8d   # 18th bit of EBX for RDSEED
*/
   mov   $0x40000, %r8d # 0x40000 is 18th bit set
   test  %ebx, %r8d
   jz    no_rdseed    # RDSEED not supported

   mov   $1,   %rax
   jmp   done_rdseed

no_rdseed:
   mov   $0,   %rax

done_rdseed:
   mov  %rsi, %rbx   # Restore RBX
   pop  %rbp
   ret


/* 64-bit random number */
_random_64:
    push  %rbp
    movq  %rsp, %rbp

retry64:
    rdrand %rax
    pause           # Useful for multithreaded applications
    jnc retry64     # Retry if carry flag was not set

    pop %rbp
    retq

/* 32-bit random number */
_random_32:
    push  %rbp
    movq  %rsp, %rbp

retry32:
    rdrand %eax
    pause           # Useful for multithreaded applications
    jnc retry32     # Retry if carry flag was not set

    pop %rbp
    retq

/* 16-bit random number */
_random_16:
    push  %rbp
    movq  %rsp, %rbp

retry16:
    rdrand %ax
    pause           # Useful for multithreaded applications
    jnc retry16     # Retry if carry flag was not set

    pop %rbp
    retq
