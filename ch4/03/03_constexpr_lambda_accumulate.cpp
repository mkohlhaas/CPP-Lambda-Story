#include <array>
#include <iostream>

// If the lambda body follows the rules of a constexpr function then,
// operator() for the closure type is IMPLICITLY defined as constexpr.

template <typename Range, typename Func, typename T>
constexpr T
SimpleAccumulate(Range &&range, Func func, T init)
{
    for (auto &&elem : range)
    {
        init += func(elem);
    }
    return init;
}

int
main()
{
    // std::array, std::begin and std::end (used in range-based for-loop) are now also constexpr
    // so it means that the whole code is executed at compile time.
    constexpr std::array arr{1, 2, 3};

    // Anonymous lambda is implicitly constexpr.
    // Explicit constexpr not needed.
    // constexpr auto sum = SimpleAccumulate(arr, [](auto i) constexpr { return i * i; }, 0);
    constexpr auto sum = SimpleAccumulate(arr, [](auto i) { return i * i; }, 0);

    static_assert(sum == 14);

    std::cout << sum << '\n'; // 14
}
