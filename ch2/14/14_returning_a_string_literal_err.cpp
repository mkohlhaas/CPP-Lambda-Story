// this code doesn't compile, intentionally

#include <iostream>

int
main()
{
    // const auto testSpeedString = [](int speed) noexcept { // int -> const char *
    // const auto testSpeedString =
    //     [](int speed) -> std::string { // ✓ (noexcept has to be removed as string allocation could fail)

    using namespace std::string_literals;

    const auto testSpeedString = [](int speed) noexcept {
        if (speed > 100)
        {
            // return "you're a super fast";
            return "you're a super fast"s;
        }

        // return "you're a regular";
        return "you're a regular"s;
    };

    auto str = testSpeedString(100);
    str += " driver";

    std::cout << str;
}
