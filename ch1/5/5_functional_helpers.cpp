#include <algorithm>
#include <functional>
#include <vector>

int
main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    // .. push back until 9...
    const size_t smaller5 = std::count_if(v.begin(), v.end(), std::bind2nd(std::less<int>(), 5));

    return smaller5;
}
