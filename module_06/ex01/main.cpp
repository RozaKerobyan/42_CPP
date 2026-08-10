#include "Serializer.hpp"

int main()
{
    Data data;
    Data *ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);
    Data *newPtr = Serializer::deserialize(raw);

    if (ptr == newPtr)
    {
        std::cout << "--- Same Pointer ---\n";
        std::cout << ptr << std::endl;
        std::cout << newPtr << std::endl;
    }
    else
    {
        std::cout << "--- Different Pointer ---\n";
        std::cout << ptr << std::endl;
        std::cout << newPtr << std::endl;
    }
    return (0);
}