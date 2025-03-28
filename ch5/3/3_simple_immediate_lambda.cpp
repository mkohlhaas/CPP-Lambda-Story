#include <iostream>
int
main()
{
    const int x = 10;

    auto lam = [](int x) consteval { return x + x; };

    std::cout << lam(x) << '\n'; // 20
}
