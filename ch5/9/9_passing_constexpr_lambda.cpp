#include <algorithm>
#include <array>
#include <iostream>

constexpr auto
countValues(auto container, auto cmp)
{
    return std::count_if(begin(container), end(container), cmp);
}

int
main()
{
    constexpr auto minVal = countValues(std::array{-10, 6, 8, 4, -5, 2, 4, 6}, //
                                        [](auto a) { return a >= 0; });        //

    std::cout << minVal << '\n';                                               // 6
}
