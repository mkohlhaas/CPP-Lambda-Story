#include <iostream>
#include <tuple>

template <class... Args>
void
captureTest(Args... args)
{
    const auto lambda = [args...] {
        const auto tup = std::make_tuple(args...);
        std::cout << "tuple size: " << std::tuple_size<decltype(tup)>::value << '\n';
        std::cout << "tuple 1st:  " << std::get<0>(tup) << '\n';
    };
    lambda(); // call it
}

int
main()
{
    captureTest(1, 2, 3, 4);
    captureTest("Hello world", 10.0f);
}
