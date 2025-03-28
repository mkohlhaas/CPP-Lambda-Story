#include <iostream>

auto
CreateMulLambda(int x) noexcept
{
    return [x](int param) noexcept { return x * param; };
}

int
main()
{
    const auto lam = CreateMulLambda(10);

    std::cout << sizeof(lam) << '\n'; // 4
    std::cout << lam(2) << '\n';      // 20
}
