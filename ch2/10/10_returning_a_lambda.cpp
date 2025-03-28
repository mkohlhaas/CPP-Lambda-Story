#include <functional>
#include <iostream>

struct Baz
{
    std::string s;

    std::function<void()>
    foo()
    {
        // return [this] { std::cout << s << '\n'; };
        return [=] { std::cout << s << '\n'; };
    }
};

int
main()
{
    auto f1 = Baz{"abc"}.foo(); //
    auto f2 = Baz{"xyz"}.foo(); //

    f1();                       // xyz
    f2();                       // xyz
}
