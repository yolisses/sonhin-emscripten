#include <iostream>

template <typename T, std::size_t N>
void print_array(const std::array<T, N> &arr)
{
    std::cout << "[";
    for (size_t i = 0; i < N; i++)
    {
        std::cout << arr[i];
        if (i < N - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}