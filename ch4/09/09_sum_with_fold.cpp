#include <iostream>

int
main()
{
    const auto sumLambda = [](auto... args) {
        std::cout << "sum of: " << sizeof...(args) << " numbers\n";
        return (args + ... + 0); // fold expressions (cp. ../ch3/10/10_generic_variadic_lambda.cpp)
    };

    std::cout << sumLambda(1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9);
}

// sum of: 9 numbers
// 49.5
