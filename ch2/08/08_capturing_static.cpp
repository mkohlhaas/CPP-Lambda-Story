#include <iostream>

void
bar()
{
    static int static_int = 10;

    std::cout << static_int << '\n'; // 10

    auto foo = [=]() mutable noexcept { ++static_int; };
    foo();
    std::cout << static_int << '\n'; // 11

    const auto increase = []() noexcept { ++static_int; };
    increase();
    std::cout << static_int << '\n'; // 12

    const auto moreIncrease = [static_int]() noexcept { ++static_int; };
    moreIncrease();
    std::cout << static_int << '\n'; // 13
}

int
main()
{
    bar();
}
