#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using map_str_int = std::map<std::string, int>;

int
main()
{
    const map_str_int numbers{
        {"one", 1},
        {"two", 2},
        {"three", 3},
    };

    // print addresses:
    for (auto mit = numbers.cbegin(); mit != numbers.cend(); ++mit)
    {
        std::cout << &mit->first << ", " << &mit->second << ": " << mit->first << " = " << mit->second << '\n';
    }

    std::cout << std::endl;

    // each time entry is copied from pair<const string, int>!
    std::for_each(std::begin(numbers),                           //
                  std::end(numbers),                             //
                  [](const std::pair<std::string, int> &entry) { //
                      std::cout << &entry.first << ", " << &entry.second << ": " << entry.first << " = " << entry.second
                                << '\n';
                  });

    std::cout << std::endl;

    // this time entries are not copied, they have the same addresses
    std::for_each(std::begin(numbers),    //
                  std::end(numbers),      //
                  [](const auto &entry) { //
                      std::cout << &entry.first << ", " << &entry.second << ": " << entry.first << " = " << entry.second
                                << '\n';
                  });
}

// 0x649e614932d0, 0x649e614932f0: one = 1
// 0x649e61493370, 0x649e61493390: three = 3
// 0x649e61493320, 0x649e61493340: two = 2
//
// 0x7ffd9f4d6490, 0x7ffd9f4d64b0: one = 1
// 0x7ffd9f4d6490, 0x7ffd9f4d64b0: three = 3
// 0x7ffd9f4d6490, 0x7ffd9f4d64b0: two = 2
//
// 0x649e614932d0, 0x649e614932f0: one = 1
// 0x649e61493370, 0x649e61493390: three = 3
// 0x649e61493320, 0x649e61493340: two = 2
