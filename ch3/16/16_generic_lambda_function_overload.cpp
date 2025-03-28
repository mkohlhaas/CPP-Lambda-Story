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
    // [1] doesn't work
    {
        // const std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
        // std::for_each(vi.begin(), vi.end(), foo);              // error: No matching function for call to 'for_each'
    }

    // [2]
    {
        // const std::vector<float> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
        const std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};

        // [](auto &&x) { return foo(std::forward<decltype(x)>(x)); }); //
        std::for_each(vi.begin(),                       //
                      vi.end(),                         //
                      [](auto &&x) { return foo(x); }); //
    }
}

// int: 1
// int: 2
// int: 3
// int: 4
// int: 5
// int: 6
// int: 7
// int: 8
// int: 9
