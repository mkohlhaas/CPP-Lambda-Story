#include <iostream>
#include <string>

// With generic lambdas you're not restricted to using auto x,
// you can add any qualifiers as with other auto variables
// like auto&, const auto& or auto&&.

void
foo(const std::string &)
{
    std::cout << "foo(const string&)\n";
}

void
foo(std::string &&)
{
    std::cout << "foo(string&&)\n";
}

int
main()
{
    // perfect forwarding with auto&& (= universal/forwarding reference)
    const auto callFoo = [](auto &&str) {
        std::cout << "Calling foo() on: " << str << '\n';
        foo(std::forward<decltype(str)>(str));
    };

    const std::string str = "Hello World";

    callFoo(str);
    // Calling foo() on: Hello World
    // foo(const string&)

    callFoo("Hello World &&");
    // Calling foo() on: Hello World &&
    // foo(string&&)
}
