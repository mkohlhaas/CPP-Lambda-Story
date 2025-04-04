#include <iostream>

int
main()
{
    // remove trailing comma
    const auto printer = [](auto first, auto... args) {
        std::cout << first;
        ((std::cout << ", " << args), ...);
        std::cout << '\n';
    };

    printer(1, 2, 3, "hello", 10.5f); // 1, 2, 3, hello, 10.5
}
