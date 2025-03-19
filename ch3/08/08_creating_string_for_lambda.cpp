#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int
main()
{
    using namespace std::string_literals;
    const std::vector<std::string> vs = {"apple", "orange", "foobar", "lemon"};

    const auto prefix = "foo"s;

    auto result = std::find_if(vs.begin(), vs.end(), [&prefix](const std::string &s) { return s == prefix + "bar"s; });
    if (result != vs.end())
    {
        std::cout << prefix << "-something found!\n";
    }

    result = std::find_if(vs.begin(), vs.end(),
                          [savedString = prefix + "bar"s](const std::string &s) { return s == savedString; });
    if (result != vs.end())
    {
        std::cout << prefix << "-something found!\n";
    }
}
