#include <iostream>

// IIFE - Immediately Invoked Functional Expression

int
main()
{
    int x = 1;
    int y = 1;

    std::cout << x << ", " << y << '\n'; // 1, 1

    [&]() noexcept {
        ++x;
        ++y;
    }(); // IIFE

    std::cout << x << ", " << y << '\n'; // 2, 2
}
