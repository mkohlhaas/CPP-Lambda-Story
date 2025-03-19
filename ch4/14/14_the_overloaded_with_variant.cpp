#include <iostream>
#include <variant>

template <class... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};
template <class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

int
main()
{
    const auto PrintVisitor = [](const auto &t) { std::cout << t << "\n"; };

    std::variant<int, float, std::string> intFloatString{"Hello"};

    std::visit(PrintVisitor, intFloatString);

    std::visit(overloaded{[](int &i) { i *= 2; }, [](float &f) { f *= 2.0f; }, [](std::string &s) { s = s + s; }},
               intFloatString);

    std::visit(PrintVisitor, intFloatString);
}
