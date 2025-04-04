#include <iostream>
#include <tuple>

// cp. ../ch5/4/4_capturing_variadic_pack.cpp
// cp. ../ch4/12/12_printing_elements_without.cpp

template <class... Args>
void
captureTest(Args... args)
{
    const auto lambda = [args...] {
        const auto tup = std::make_tuple(args...);

        std::cout << "tuple size: " << std::tuple_size_v<decltype(tup)> << '\n';
        std::cout << "tuple 1st:  " << std::get<0>(tup) << '\n';
    };

    lambda();
}

int
main()
{
    captureTest(1, 2, 3, 4);           // tuple size: 4 | tuple 1st: 1
    captureTest("Hello world", 10.0f); // tuple size: 2 | tuple 1st: Hello world
}
