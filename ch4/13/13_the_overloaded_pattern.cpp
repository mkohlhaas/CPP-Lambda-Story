#include <iostream>

// Overloaded Pattern

template <class... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};

// not needed in C++20:
// template <class... Ts>
// overloaded(Ts...) -> overloaded<Ts...>;

int
main()
{
    const auto test = overloaded{[](const int &i) { std::cout << "int: " << i << '\n'; },
                                 [](const float &f) { std::cout << "float: " << f << '\n'; },
                                 [](const std::string &s) { std::cout << "string: " << s << '\n'; }};

    test(10);      // int: 10
    test(10.0f);   // float: 10
    test("10.0f"); // string: 10.0f

    // test(10.0); // error
}
