#include <iostream>

struct Baz
{
    std::string s;

    void
    foo()
    {
        const auto lam = [s]() { std::cout << s; };
        lam();
    }
};

int
main()
{
    Baz b;
    b.foo();
}
