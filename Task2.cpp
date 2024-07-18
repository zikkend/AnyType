#include <iostream>
#include <typeinfo>
#include <string>
#include <stdexcept>
#include <utility>

#include "AnyType.h"

int main() {
    try {
        AnyType anyType = 1;
        anyType = true;
        anyType = 1.7;

        int storedValue = anyType.get<int>(); // Throws bad_cast exception
    }
    catch (const std::bad_cast& e) {
        std::cout << "Bad cast exception: " << e.what() << std::endl;
    }

    try {
        AnyType anyType = 1.7;
        double storedValue = anyType.get<double>();
        std::cout << "Stored double value: " << storedValue << std::endl;
    }
    catch (const std::bad_cast& e) {
        std::cout << "Bad cast exception: " << e.what() << std::endl;
    }

    try {
        AnyType anyType = 1.7;
        double storedValue = anyType.get<float>();
        std::cout << "Stored double value: " << storedValue << std::endl;
    }
    catch (const std::bad_cast& e) {
        std::cout << "Bad cast exception: " << e.what() << std::endl;
    }

    AnyType anyType1 = 23, anyType2 = 1.5;


    return 0;
}
