#include <functional>
#include <iostream>

struct Baz
{
    std::function<void()>
    foo()
    {
        // Implicit capture of 'this' with a capture default of '=' is deprecated
        // return [=] { std::cout << s << std::endl; };
        return [=, *this] { std::cout << s << std::endl; };
    }

    std::string s;
};

int
main()
{
    auto f1 = Baz{"ala"}.foo();
    auto f2 = Baz{"ula"}.foo();

    f1(); // ala
    f2(); // ula
}
