#include <functional>

int
main()
{
    const std::function<int(int)> factorial = [&factorial](int n) { return n > 1 ? n * factorial(n - 1) : 1; };
    return factorial(5);
}
