#include "Architecture/Inheritance.h"
#include <iostream>

int main(int argc, char* argv[])
{
    // Example usage
    DerivedClass obj(1.0f, 2.0f, 3.0f, 4.0f);

    std::cout << "x: " << obj.getX() << std::endl;
    std::cout << "y: " << obj.getY() << std::endl;
    std::cout << "z: " << obj.getZ() << std::endl;
    std::cout << "w: " << obj.getW() << std::endl;
    
    return 0;
}
