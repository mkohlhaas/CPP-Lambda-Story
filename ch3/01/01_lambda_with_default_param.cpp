#include <iostream>

int
main()
{
    const auto lam = [](int x = 10) { std::cout << x << '\n'; };
    lam();
    lam(100);
}
