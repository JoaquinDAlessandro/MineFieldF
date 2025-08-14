#include <MineField/Utils/intFunctions.h>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

namespace intFunctions
{
    void  initRandom()
    {
        static bool initialized = false;
        if (!initialized)
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            initialized = true;
        }
    }

    int getRandomInt(unsigned int min, unsigned int max)
    {
        initRandom();
        if (min >= max)
        {
            return min;
        }
        return min + (std::rand() % (max - min));
    }
}
