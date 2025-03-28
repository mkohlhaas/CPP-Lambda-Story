#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using map_str_int  = std::map<std::string, int>;
using pair_str_int = std::pair<std::string, int>;
int
main()
{
    const map_str_int numbers{
        {"one", 1},
        {"two", 2},
        {"three", 3},
    };

    // each time entry is copied from pair<const string, int>!
    std::for_each(std::begin(numbers),                                           //
                  std::end(numbers),                                             //
                  [](const pair_str_int &entry) {                                //
                      std::cout << entry.first << " = " << entry.second << '\n'; //
                  });                                                            //

    // one = 1
    // three = 3
    // two = 2
}
