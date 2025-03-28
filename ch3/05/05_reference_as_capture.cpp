#include <iostream>

int
main()
{
    int x = 30;

    const auto foo = [&z = x]() { std::cout << z << '\n'; };

    foo(); // 30

    x = 0;
    foo(); // 0
}
