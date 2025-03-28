#include <functional>
#include <iostream>

int
main()
{
    const std::function<int(int)> factorial = [&factorial](int n) { return n > 1 ? n * factorial(n - 1) : 1; };

    std::cout << factorial(5) << '\n'; // 120
}
