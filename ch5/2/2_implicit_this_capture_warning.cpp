#include <functional>
#include <iostream>

struct Baz
{
    std::function<void()>
    foo()
    {
        return [=] { std::cout << s << std::endl; };
    }

    std::string s;
};

int
main()
{
    auto f1 = Baz{"ala"}.foo();
    auto f2 = Baz{"ula"}.foo();

    f1(); // ula
    f2(); // ula
}
