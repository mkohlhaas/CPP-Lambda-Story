#include <iostream>

int
main()
{
    const auto print = [](const char *str, int x, int y) { std::cout << str << ": " << x << " " << y << '\n'; };

    int x = 1;
    int y = 1;

    print("in main()", x, y);            // in main(): 1 1

    auto foo = [x, y, print]() mutable { //
        ++x;
        ++y;
        print("in foo() ", x, y);        //
    };

    foo();                               // in foo() : 2 2

    print("in main()", x, y);            // in main(): 1 1
}
