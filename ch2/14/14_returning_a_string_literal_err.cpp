// this code doesn't compile, intentionally

#include <iostream>
#include <string>

int
main()
{
    const auto testSpeedString = [](int speed) noexcept {
        if (speed > 100)
        {
            return "you're a super fast";
        }

        return "you're a regular";
    };

    auto str = testSpeedString(100);
    str += " driver"; // oops! no += on const char*!

    std::cout << str;

    return 0;
}
