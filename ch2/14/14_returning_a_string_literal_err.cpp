// this code doesn't compile, intentionally

#include <iostream>

int
main()
{
    const auto testSpeedString = [](int speed) noexcept { // int -> const char *
        if (speed > 100)
        {
            return "you're a super fast";
        }

        return "you're a regular";
    };

    auto str = testSpeedString(100); // const char *
    str += " driver";                // oops!

    std::cout << str;
}
