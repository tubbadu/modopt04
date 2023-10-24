#include "Counter.h"

void Counter::printNumbers(){
    for(int i = max; i >= min; i--)
        std::cout << i << std::endl;
}