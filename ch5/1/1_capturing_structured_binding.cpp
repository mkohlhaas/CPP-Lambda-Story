#include <iostream>
#include <string>
#include <tuple>

auto
getParams()
{
    return std::tuple{std::string{"Hello World"}, 42};
}
int

main()
{
    auto [x, y] = getParams();

    // capturing a structured binding in a lambda
    const auto paramLength = [&x, &y]() { return x.length() + y; }();

    std::cout << paramLength << '\n'; // 53
}
