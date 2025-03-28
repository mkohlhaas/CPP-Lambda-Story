#include <iostream>

int
factorial(int n)
{
    return n > 1 ? n * factorial(n - 1) : 1;
}

int
main()
{
    std::cout << factorial(5) << '\n'; // 120
}
