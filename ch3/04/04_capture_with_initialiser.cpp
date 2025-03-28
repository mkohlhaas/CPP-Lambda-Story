#include <iostream>

int
main()
{
    int x = 30;
    int y = 12;

    const auto foo = [z = x + y]() { std::cout << z << '\n'; };

    x = 0;
    y = 0;

    foo(); // 42
}
