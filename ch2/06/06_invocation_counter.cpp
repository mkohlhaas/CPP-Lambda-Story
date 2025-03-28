#include <algorithm>
#include <iostream>
#include <vector>

int
main()
{
    std::vector<int> vec{0, 5, 2, 9, 7, 6, 1, 3, 4, 8};

    for (const auto &v : vec)
    {
        std::cout << v << ", "; // 0, 5, 2, 9, 7, 6, 1, 3, 4, 8
    }

    std::cout << std::endl;

    size_t compCounter = 0;
    std::sort(vec.begin(), vec.end(), [&compCounter](int a, int b) noexcept {
        ++compCounter;
        return a < b;
    });

    std::cout << "number of comparisons: " << compCounter << '\n'; // number of comparisons: 36

    for (const auto &v : vec)
    {
        std::cout << v << ", ";                                    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    }
}
