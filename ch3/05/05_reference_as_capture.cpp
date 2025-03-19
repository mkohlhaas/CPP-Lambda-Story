#include <iostream>

int
main()
{
    int        x   = 30;
    const auto foo = [&z = x]() { std::cout << z << '\n'; };
    foo();
    x = 0;
    foo();
}
