#include <iostream>

// Default Parameters for Lambdas

int
main()
{
    const auto lam = [](int x = 10) { std::cout << x << '\n'; };

    lam();    // 10
    lam(100); // 100
}
