#ifndef PRINT_ARRAY_H
#define PRINT_ARRAY_H

#include <array>

template <typename T, std::size_t N>
void print_array(const std::array<T, N> &arr);

#include "print_array.cpp" // Include the implementation file

#endif // PRINT_ARRAY_H
