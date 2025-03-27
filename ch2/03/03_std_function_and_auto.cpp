#include <functional>
#include <iostream>

int
main()
{
    const auto myLambda = [](int a) noexcept -> double { return 2.0 * a; };

    const std::function<double(int)> myFunc = [](int a) noexcept -> double { return 2.0 * a; };

    std::cout << "sizeof(myLambda) = " << sizeof(myLambda) << '\n';
    std::cout << "sizeof(myFunc)   = " << sizeof(myFunc) << '\n';

    std::cout << std::boolalpha << (myLambda(10) == myFunc(10)) << std::endl;
}
