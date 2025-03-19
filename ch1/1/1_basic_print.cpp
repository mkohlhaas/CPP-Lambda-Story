#include <algorithm>
#include <iostream>
#include <vector>

void
PrintFunc(int x)
{
    std::cout << x << '\n';
}

int
main()
{
    std::vector<int> v;
    v.push_back(1); // no uniform initialisation in C++03!
    v.push_back(2); // push_back available only... :)
    std::for_each(v.begin(), v.end(), PrintFunc);
}
