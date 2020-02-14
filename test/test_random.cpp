#include <iostream>

#include "intel_random.h"

class RandomNumber
{
    public:
        static bool IsRdrandAvailable ()
        {
            return is_rdrand_available();
        }

        static bool IsRdseedAvailable ()
        {
            return is_rdseed_available();
        }
#ifdef __x86_64__
        static uint64_t GetNextRandom64 ()
        {
            return random_64();
        }
#endif

        static uint32_t GetNextRandom32 ()
        {
            return random_32();
        }

        static uint16_t GetNextRandom16 ()
        {
            return random_16();
        }
    
    private:
        RandomNumber () { }
        virtual ~RandomNumber () = 0;
};

void GenerateRandomNumbers()
{
    // Generate a random number ([1..65535]) of random numbers
    const uint16_t NUM_OF_RAND = random_16();
    std::cout << "Generating " << NUM_OF_RAND << " random numbers..." << std::endl;

    for (int i = 0; i < NUM_OF_RAND; i++) {
#ifdef __x86_64__
        uint64_t r64 = RandomNumber::GetNextRandom64();
        std::cout << "64-bit Random Number: " << r64 << std::endl;
#endif
        uint32_t r32 = RandomNumber::GetNextRandom32(); 
        uint16_t r16 = RandomNumber::GetNextRandom16(); 

        std::cout << "32-bit Random Number: " << r32 << std::endl;
        std::cout << "16-bit Random Number: " << r16 << std::endl;

        printf("----------------------------------\n");
    }

    std::cout << "Generated " << NUM_OF_RAND << " random numbers..." << std::endl;
}

int main (int argc, char *argv[])
{
    if (RandomNumber::IsRdrandAvailable()) {
        std::cout<< "Intel DRNG RDRAND Support Available" << std::endl;
        GenerateRandomNumbers();
    } else {
        std::cout<< "Intel DRNG RDRAND Support Not Available" << std::endl;
    }

    if (RandomNumber::IsRdseedAvailable()) {
        std::cout << "Intel DRNG RDSEED Support Available" << std::endl;
    } else {
        std::cout << "Intel DRNG RDSEED Support Not available" << std::endl;
    }

    return 0;
}
