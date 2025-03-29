#include <iostream>

int
main()
{
    const auto printer = [](auto... args)    //
    { (std::cout << ... << args) << '\n'; }; // fold expression

    printer(1, 2, 3, "hello", 10.5f);        // 123hello10.5
}
