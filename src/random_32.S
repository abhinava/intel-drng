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
.global rdseed_capability

/*
 * Returns 1 if RDRAND capability is available; 0 otherwise
 */
rdrand_capability:
   push  %ebp
   mov   %esp, %ebp

   mov   %ebx, %esi   # Save EBX since CPUID clobbers EBX

   mov   $1,   %eax
   cpuid
   
   /*
    mov   $1,   %edi
    shl   $30,  %edi   # 30th bit of ECX for RDRAND
   */
   mov   $0x40000000, %edi # 0x40000000 is 30th bit set
   test  %ecx, %edi
   jz    no_rdrand    # RDRAND not supported

   mov   $1,   %eax
   jmp   done_rdrand

no_rdrand:
   mov   $0,   %eax

done_rdrand:
   mov  %esi, %ebx   # Restore EBX
   pop  %ebp
   ret

/*
 * Returns 1 if RDSEED capability is available; 0 otherwise
 */
rdseed_capability:
   push  %ebp
   mov   %esp, %ebp

   mov   %ebx, %esi   # Save EBX since CPUID clobbers EBX

   mov   $7,   %eax   # EAX=7 & ECX=0 to get Extended Features
   mov   $0,   %ecx
   cpuid

/*
   mov   $1,   %edi
   shl   $18,  %edi   # 18th bit of EBX for RDSEED
*/
   mov   $0x40000, %edi # 0x40000 is 18th bit set
   test  %ebx, %edi
   jz    no_rdseed    # RDSEED not supported

   mov   $1,   %eax
   jmp   done_rdseed

no_rdseed:
   mov   $0,   %eax

done_rdseed:
   mov  %esi, %ebx   # Restore EBX
   pop  %ebp
   ret

/* 32-bit random number */
random_32:
    push %ebp
    mov  %esp, %ebp

retry32:
    rdrand %eax
    pause           # Useful for multithreaded applications
    jnc retry32     # Retry if carry flag was not set

    pop %ebp
    ret

/* 16-bit random number */
random_16:
    push %ebp
    mov  %esp, %ebp

retry16:
    rdrand %ax
    pause           # Useful for multithreaded applications
    jnc retry16     # Retry if carry flag was not set

done16:
    pop %ebp
    ret
