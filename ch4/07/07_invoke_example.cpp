#include <functional>
#include <iostream>
#include <string>

// IIFE = Immediately Invoked Function Expression

int
main()
{
    const std::string in{"Hello World"};

    // IIFE
    const std::string out1 = [copy = in]() mutable {
        copy.replace(copy.find("World"), 5, "C++");
        return copy;
    }();

    // the same, but makes IIFE  more visible
    const std::string out2 = std::invoke([copy = in]() mutable {
        copy.replace(copy.find("World"), 5, "C++");
        return copy;
    });

    std::cout << out1; // Hello C++
    std::cout << out2; // Hello C++
}
