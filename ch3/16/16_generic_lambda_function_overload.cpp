#include <algorithm>
#include <iostream>
#include <vector>

void
foo(int i)
{
    std::cout << "int: " << i << "\n";
}
void
foo(float f)
{
    std::cout << "float: " << f << "\n";
}

int
main()
{
    const std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::for_each(vi.begin(), vi.end(), [](auto &&x) { return foo(std::forward<decltype(x)>(x)); });
}
