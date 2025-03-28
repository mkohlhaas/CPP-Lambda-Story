#include <functional>
#include <iostream>

// Before C++14 you could use std::function for the return type.

std::function<int(int)>
CreateMulLambda(int x)
{
    return [x](int param) noexcept { return x * param; };
}

int
main()
{
    const auto lam = CreateMulLambda(10);

    std::cout << sizeof(lam) << '\n'; // 32
    std::cout << lam(2) << '\n';      // 20
}
