#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

int
main()
{
    std::vector<int> vec(1000);
    std::iota(vec.begin(), vec.end(), 0);
    std::vector<int> output;
    std::for_each(std::execution::par, vec.begin(), vec.end(), [&output](int &elem) {
        if (elem % 2 == 0)
        {
            output.push_back(elem);
        }
    });

    for (const auto &elem : output)
    {
        std::cout << elem << ", ";
    }
}
