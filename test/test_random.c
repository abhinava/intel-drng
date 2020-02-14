#include <stdio.h>
#include <inttypes.h>

#include "intel_drng.h"

static void generate_random_numbers()
{
    // Generate a random number ([1..65535]) of random numbers
    const uint16_t NUM_OF_RAND = random_16();
    printf ("Generating %d random numbers...\n", NUM_OF_RAND);

    for (int i = 0; i < NUM_OF_RAND; i++) {
#ifdef __x86_64__
        uint64_t r64 = random_64();
        printf("64-bit Random Number: %" PRIu64 "\n", r64);
#endif
        uint32_t r32 = random_32();
        uint16_t r16 = random_16();

        printf("32-bit Random Number: %" PRIu32 "\n", r32);
        printf("16-bit Random Number: %" PRIu16 "\n", r16);

        printf("----------------------------------\n");
    }

    printf ("Generated %d random numbers...\n", NUM_OF_RAND);
}

int main (int argc, char *argv[])
{
    if (is_rdrand_available()) {
        printf("Intel DRNG RDRAND Support Available\n");
        generate_random_numbers();
    } else {
        printf("Intel DRNG RDRAND Support Not available\n");
    }

    if (is_rdseed_available()) {
        printf("Intel DRNG RDSEED Support Available\n");
    } else {
        printf("Intel DRNG RDSEED Support Not available\n");
    }

    return 0;
}
