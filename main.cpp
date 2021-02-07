#include <iostream>
#include <exception>

#include "config.h"

int main([[maybe_unused]]int argc,[[maybe_unused]] char*argv[])
{
    std::cout << "Hello world!" << std::endl;
    std::cout << get_config_string() << std::endl;
    std::cout << "result:" << complex_calculation(2,2) << std::endl;
    return 0;
}