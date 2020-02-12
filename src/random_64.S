/**
 *
 * Simple x86_64 assembly routines to retrieve 64-bit, 32-bit
 * and 16-bit true random numbers and random number seeds 
 * using Intel's DRNG instructions.
 *
 * TODO:
 *   - Provide RDSEED instruction support
 *
 * Reference:
 *  - https://software.intel.com/en-us/articles/intel-digital-random-number-generator-drng-software-implementation-guide
 *  - https://software.intel.com/en-us/blogs/2012/11/17/the-difference-between-rdrand-and-rdseed
 *
 * Abhinava Sadasivarao (abhinava.sadasivarao@gmail.com)
 *
 */

.global random_64
.global random_32
.global random_16
.global rdrand_capability

/*
 * Returns 1 if RDRAND capability is available; 0 otherwise
 */
rdrand_capability:
   push  %rbp
   movq  %rsp, %rbp

   movq  $1,   %rax
   cpuid

   movl  $1,   %r8d
   shl   $30,  %r8d   # 30th bit of ECX for RDRAND
   test  %ecx, %r8d
   je    no           # RDRAND not supported

   movq  $1,   %rax
   jmp   done

no:
   movq  $0,   %rax

done:
   popq %rbp
   retq

/* 64-bit random number */
random_64:
    push  %rbp
    movq  %rsp, %rbp

retry64:
    rdrand %rax
    jnc retry64     # Retry if carry flag was not set

    pop %rbp
    retq

/* 32-bit random number */
random_32:
    push  %rbp
    movq  %rsp, %rbp

retry32:
    rdrand %eax
    jnc retry32     # Retry if carry flag was not set

    pop %rbp
    retq

/* 16-bit random number */
random_16:
    push  %rbp
    movq  %rsp, %rbp

retry16:
    rdrand %ax
    jnc retry16     # Retry if carry flag was not set

    pop %rbp
    retq
