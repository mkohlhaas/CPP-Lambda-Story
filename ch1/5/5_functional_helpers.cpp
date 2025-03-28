#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int
main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    const size_t smaller5 = std::count_if(v.begin(), v.end(), std::bind2nd(std::less<int>(), 5));

    std::cout << smaller5 << '\n'; // 4
}
