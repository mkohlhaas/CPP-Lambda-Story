#include <iostream>
int
main()
{
    {
        int x = 10;

        auto lam = [](int x) constexpr { return x + x; };

        std::cout << lam(x) << '\n'; // 20
    }

    {
        const int x = 10;

        // consteval conform to the rules of a constexpr function
        // but can be only evaluated at compile-time
        // Such lambda functions are also called "immediate functions".
        auto lam = [](int x) consteval { return x + x; };

        std::cout << lam(x) << '\n'; // 20
    }
}
