#include <stdio.h>
#include <inttypes.h>

#include "intel_random.h"

int main (int argc, char *argv[])
{
    if (is_random_available()) {
        printf("Intel DRNG Support Available\n");
    } else {
        printf("Intel DRNG Support Not available\n");
        return -1;
    }

    // Generate a random number of [1..65535] random numbers
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

    return 0;
}
