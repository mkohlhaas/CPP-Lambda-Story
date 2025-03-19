#include <iostream>

struct Baz
{
    void
    foo()
    {
        const auto lam = [s]() { std::cout << s; };
        lam();
    }

    std::string s;
};

int
main()
{
    Baz b;
    b.foo();
}
