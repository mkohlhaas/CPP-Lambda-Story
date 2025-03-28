#include <iostream>

// CAPTURE WITH AN INITIALISER or another name for this feature is
// GENERALISED LAMBDA CAPTURE.

int
main()
{
    int x = 30;
    int y = 12;

    // The new variable is initialised at the place where you define a lambda and not where you invoke it.
    // That's why if you modify the x or y variables after you created the lambda, the variable z won’t change.
    const auto foo = [z = x + y]() { std::cout << z << '\n'; };

    x = 0;
    y = 0;

    foo(); // 42
}
