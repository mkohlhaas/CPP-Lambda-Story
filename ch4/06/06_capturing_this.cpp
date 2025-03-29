#include <iostream>

// Should we capture [this] or [*this], and why is this important?
//
// In most cases, when you work inside the scope of a class, then [this] (or [&]) is perfectly
// fine. There’s no extra copy which is essential when your objects are large.
//
// You might consider [*this] when you really want a copy, and when there’s a chance a
// lambda will outlive the object.

struct Baz
{
    auto
    foo()
    {
        // We capture the original object!
        // return [this] { std::cout << s << '\n'; }; // abc abc

        // Lambda captures a copy of the temporary
        // object, a copy of *this.
        return [*this] { std::cout << s << '\n'; }; // xyz abc
    }

    std::string s;
};

int
main()
{
    const auto f1 = Baz{"xyz"}.foo();
    const auto f2 = Baz{"abc"}.foo();

    f1(); // xyz
    f2(); // abc
}
