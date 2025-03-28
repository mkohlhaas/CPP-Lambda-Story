#include <algorithm>
#include <iostream>
#include <map>
#include <string>

// Deducing the Correct Type

using map_str_int = std::map<std::string, int>;

// Did I make any mistake here? Does entry have the correct type?
using map_entry = std::pair<std::string, int>;

// The code is wrong as the value type for std::map is std::pair<const Key, T> and not
// const std::pair<Key, T>. For our case, the code performed EXTRA COPIES due to the conver-
// sion between std::pair<const std::string, int> and const std::pair<std::string,
// int>& (ie. const std::string to std::string)

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
                  [](const map_entry &entry) {                                   //
                      std::cout << entry.first << " = " << entry.second << '\n'; //
                  });                                                            //

    // just use auto (correct type deduction, easier to read, no extra copies)
    std::for_each(std::begin(numbers),                                                                   //
                  std::end(numbers),                                                                     //
                  [](const auto &entry) { std::cout << entry.first << " = " << entry.second << '\n'; }); //

    // one = 1
    // three = 3
    // two = 2
    // one = 1
    // three = 3
    // two = 2
}
