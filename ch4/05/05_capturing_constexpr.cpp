#include <iostream>

constexpr int
add(int const &t, int const &u)
{
    return t + u;
}

int
main()
{
    constexpr int  x   = 11;
    constexpr auto lam = [x](int n) { return add(x, n); };

    static_assert(lam(10) == 21);

    std::cout << lam(10) << '\n'; // 21
}
