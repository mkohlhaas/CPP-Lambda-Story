#include <iostream>

// Capturing a Class Data Member

struct Baz
{
    auto
    foo() const
    {
        // capturing a class data member
        return [s = s] { std::cout << s << '\n'; };
    }

    std::string s;
};

int
main()
{
    const auto f1 = Baz{"abc"}.foo();
    const auto f2 = Baz{"xyz"}.foo();

    f1(); // abc
    f2(); // xyz
}
