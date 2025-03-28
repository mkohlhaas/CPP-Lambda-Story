#include <iostream>

int global = 10;

int
main()
{
    std::cout << global << '\n'; // 10

    auto foo = [=]() mutable noexcept { ++global; };
    foo();
    std::cout << global << '\n'; // 11

    const auto increaseGlobal = []() noexcept { ++global; };
    increaseGlobal();
    std::cout << global << '\n'; // 12

    const auto moreIncreaseGlobal = [global]() noexcept { ++global; };
    moreIncreaseGlobal();
    std::cout << global << '\n'; // 13
}
