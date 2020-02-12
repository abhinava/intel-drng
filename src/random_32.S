/**
 *
 * Simple x86 assembly routines to retrieve 32-bit and
 * 16-bit true random numbers and random number seeds 
 * using Intel's DRNG instructions.
 * 
 * TODO:
 *   - Provide RDSEED instruction support
 * 
 * Reference:
 *  - https://software.intel.com/en-us/articles/intel-digital-random-number-generator-drng-software-implementation-guide
 *  - https://software.intel.com/en-us/blogs/2012/11/17/the-difference-between-rdrand-and-rdseed

 * Abhinava Sadasivarao (abhinava.sadasivarao@gmail.com)
 *
 */

.global random_32
.global random_16
.global rdrand_capability

/*
 * Returns 1 if RDRAND capability is available; 0 otherwise
 */
rdrand_capability:
   push  %ebp
   mov   %esp, %ebp

   mov   $1,   %eax
   cpuid

   mov   $1,   %edi
   shl   $30,  %edi   # 30th bit of ECX for RDRAND
   test  %ecx, %edi
   je    no           # RDRAND not supported

   mov   $1,   %eax
   jmp   done

no:
   mov   $0,   %eax

done:
   pop  %ebp
   ret


/* 32-bit random number */
random_32:
    push %ebp
    mov  %esp, %ebp

retry32:
    rdrand %eax
    jnc retry32     # Retry if carry flag was not set

    pop %ebp
    ret

/* 16-bit random number */
random_16:
    push %ebp
    mov  %esp, %ebp

retry16:
    rdrand %ax
    jnc retry16     # Retry if carry flag was not set

done16:
    pop %ebp
    ret
