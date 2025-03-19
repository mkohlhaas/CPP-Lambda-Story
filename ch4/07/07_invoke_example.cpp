#include <functional> // invoke()
#include <iostream>
#include <string>

int
main()
{
    const std::string in{"Hello World"};
    const std::string out = std::invoke([copy = in]() mutable {
        copy.replace(copy.find("World"), 5, "C++");
        return copy;
    });
    std::cout << out;
}
