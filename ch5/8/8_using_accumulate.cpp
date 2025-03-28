#include <array>
#include <iostream>
#include <numeric>

int
main()
{
    constexpr std::array arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // with constexpr lambda
    static_assert(std::accumulate(begin(arr), end(arr), 0, [](auto a, auto b) noexcept { return a + b; }) == 55);

    std::cout << arr[0] << '\n'; // 1
}
