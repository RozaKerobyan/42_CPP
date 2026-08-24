#include "iter.hpp"

int main()
{
    std::cout << "--- Test for int ---\n";
    int int_arr[3] = {16, 8, 4};
    iter(int_arr, 3, print);
    std::cout << "\n";

    std::cout << "--- Test for char ---\n";
    char char_arr[8] = "Armenia";
    iter(char_arr, 7, print);
    std::cout << "\n";

    std::cout << "--- Test for string ---\n";
    std::string string_arr[3] = {"Welcome", "to", "42"};
    iter(string_arr, 3, print);
    std::cout << "\n";

    std::cout << "--- Test for double ---\n";
    double double_arr[3] = {16.001, 32.012, 64.023};
    iter(double_arr, 3, print);
    std::cout << "\n";

    std::cout << "--- Test for float ---\n";
    float float_arr[3] = {128.01f, 256.02f, 512.03f};
    iter(float_arr, 3, print);
    std::cout << "\n";
}