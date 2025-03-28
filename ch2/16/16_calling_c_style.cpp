#include <cstdlib>
#include <iostream>

int
main()
{
    int values[] = {8, 9, 2, 5, 1, 4, 7, 3, 6};

    for (const auto &val : values)
    {
        std::cout << val << ", ";                                      // 8, 9, 2, 5, 1, 4, 7, 3, 6,
    }

    constexpr size_t numElements = sizeof(values) / sizeof(values[0]); // 9

    // qsort is from the C standard library which expects a function pointer
    std::qsort(values, numElements, sizeof(int),
               // automatic conversion to function pointer
               [](const void *a, const void *b) noexcept { return (*(int *)b - *(int *)a); });

    for (const auto &val : values)
    {
        std::cout << val << ", "; // 9, 8, 7, 6, 5, 4, 3, 2, 1,
    }
}
