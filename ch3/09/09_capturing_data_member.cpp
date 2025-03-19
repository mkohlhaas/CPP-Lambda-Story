#include <algorithm>
#include <iostream>

struct Baz
{
    auto
    foo() const
    {
        return [s = s] { std::cout << s << '\n'; };
    }

    std::string s;
};

int
main()
{
    const auto f1 = Baz{"abc"}.foo();
    const auto f2 = Baz{"xyz"}.foo();
    f1();
    f2();
}
