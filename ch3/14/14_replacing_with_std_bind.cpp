#include <functional>
#include <iostream>

int
main()
{
    using std::placeholders::_1;

    // [1] std::bind
    const auto onePlus  = std::bind(std::plus<int>(), _1, 1);  // (_ + 1)
    const auto oneMinus = std::bind(std::minus<int>(), 1, _1); // (1 - _)
    std::cout << onePlus(10) << ", " << oneMinus(10) << '\n';  // 11, -9

    // [2] lambda
    auto lamOnePlus1  = [](int b) { return 1 + b; };
    auto lamMinusOne1 = [](int b) { return 1 - b; };
    std::cout << lamOnePlus1(10) << ", " << lamMinusOne1(10) << '\n'; // 11, -9

    // [3] since C++14 we could also take advantage of capture with initialiser
    auto lamOnePlus  = [a = 1](int b) { return a + b; };
    auto lamMinusOne = [a = 1](int b) { return a - b; };
    std::cout << lamOnePlus(10) << ", " << lamMinusOne(10) << '\n'; // 11, -9
}
