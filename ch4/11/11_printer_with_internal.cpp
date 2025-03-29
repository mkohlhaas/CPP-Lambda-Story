#include <iostream>

int
main()
{
    const auto printer1 = [](auto... args) {
        // helper
        const auto printElem = [](auto elem) { std::cout << elem << ", "; };

        (printElem(args), ...); // fold over comma operator rather than over <<

        std::cout << '\n';
    };

    // shorter version
    const auto printer2 = [](auto... args) {
        ((std::cout << args << ", "), ...);
        std::cout << '\n';
    };

    printer1(1, 2, 3, "hello", 10.5f); // 1, 2, 3, hello, 10.5,
    printer2(1, 2, 3, "hello", 10.5f); // 1, 2, 3, hello, 10.5,
}
