// this doesn't compile, intentionally

#include <iostream>

int
main()
{
    // direct translation of 17/17_recursion_with_regular_function.cpp
    auto factorial = [](int n)                    //
    { return n > 1 ? n * factorial(n - 1) : 1; }; //

    std::cout << factorial(5) << '\n';
}
