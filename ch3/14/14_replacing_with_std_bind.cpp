#include <functional>
#include <iostream>

int
main()
{
    using std::placeholders::_1;

    const auto onePlus  = std::bind(std::plus<int>(), _1, 1);  // (_ + 1)
    const auto oneMinus = std::bind(std::minus<int>(), 1, _1); // (1 - _)

    std::cout << onePlus(10) << ", " << oneMinus(10) << '\n';  // 11, -9
}
