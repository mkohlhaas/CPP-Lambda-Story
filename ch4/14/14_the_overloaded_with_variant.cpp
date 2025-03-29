#include <iostream>
#include <variant>

// Application of Overloaded Pattern

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
    const auto PrintVisitor = [](const auto &t) { std::cout << t << "\n"; };

    // variant is like union type
    std::variant<int, float, std::string> intFloatString{"Hello"};

    // [1]
    {
        std::visit(PrintVisitor, intFloatString); // Hello
    }

    // [2]
    {
        // changes intFloatString
        std::visit(overloaded{
                       [](int &i) { i *= 2; },
                       [](float &f) { f *= 2.0f; },
                       [](std::string &s) { s = s + s; },
                   },
                   intFloatString);

        std::visit(PrintVisitor, intFloatString); // HelloHello
    }

    // [3]
    {
        std::visit(PrintVisitor, intFloatString); // HelloHello
    }
}
