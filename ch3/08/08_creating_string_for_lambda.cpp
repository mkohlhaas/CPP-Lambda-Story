#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std::string_literals;

using vec_strings = std::vector<std::string>;

int
main()
{
    const vec_strings vs = {"apple", "orange", "foobar", "lemon"};

    // "foo"s represents a std::string object
    const auto prefix = "foo"s;

    // [1]
    {
        auto result = std::find_if(vs.begin(),                                                        //
                                   vs.end(),                                                          //
                                   [&prefix](const std::string &s) { return s == prefix + "bar"s; }); //

        if (result != vs.end())
        {
            std::cout << prefix << "-something found!\n"; // foo-something found!
        }
    }

    // [2]
    {
        // Rather than computing some value every time we invoke a lambda, we can compute it once in the initialiser.
        auto result =
            std::find_if(vs.begin(),                                                                          //
                         vs.end(),                                                                            //
                         [savedString = prefix + "bar"s](const std::string &s) { return s == savedString; }); //

        if (result != vs.end())
        {
            std::cout << prefix << "-something found!\n"; // foo-something found!
        }
    }
}
