#include <iostream>

int
main()
{
    int x = 1, y = 1;
    [&]() noexcept {
        ++x;
        ++y;
    }(); // <-- call ()
    std::cout << x << ", " << y;
}
