#include <iostream>

template <typename T>
auto
sum(T x)
{
    return x;
}

template <typename T1, typename... T>
auto
sum(T1 s, T... ts)
{
    return s + sum(ts...);
}

int
main()
{
    // generic lambdas with auto captures and
    // variadic generic arguments
    // auto... = variadic argument pack
    const auto sumLambda = [](auto... args) {
        std::cout << "sum of: " << sizeof...(args) << " numbers\n";
        return sum(args...);
    };

    std::cout << sumLambda(1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9); // sum of: 9 numbers | 49.5
}
