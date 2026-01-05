#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.value = 344;

    Data* originalPtr = &data;

    unsigned long raw = Serializer::serialize(originalPtr);
    std::cout << "Adresse converte in integer: " << raw << std::endl;

    Data* recoveredPtr = Serializer::deserialize(raw);
    if (originalPtr == recoveredPtr) {
        std::cout << "Good" << std::endl;
        std::cout << "Value = " << recoveredPtr->value << std::endl;
    } else 
    {
        std::cout << "Error" << std::endl;
    }

    return 0;
}
