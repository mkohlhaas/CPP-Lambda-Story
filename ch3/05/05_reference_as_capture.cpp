#include <iostream>

int
main()
{
    int x = 30;

    // capture as a reference
    const auto foo = [&z = x]() { std::cout << z << '\n'; };

    foo(); // 30
    x = 0; // z references x and reflects it
    foo(); // 0
}
