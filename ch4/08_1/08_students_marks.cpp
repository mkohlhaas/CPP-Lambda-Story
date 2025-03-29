#include <iostream>
#include <numeric>
#include <vector>

// function extraction with IIFE (p.89)

// 1. Wrap the code you want to extract with IIFE and capture all by reference [&].
// 2. Compile the code. The compiler will complain about variables inside IIFE and not
//    visible outside. This will be the output (return) of the IIFE.
// 3. Now remove “capture all by reference” and compile. The compiler will report variables
//    that we need to pass into the lambda as parameters.
// 4. Create a name for the new function and copy the code from IIFE.

using mark    = double;
using name    = std::string;
using marks   = std::vector<mark>;
using Student = std::pair<marks, name>;

auto
ComputeAverages(const std::vector<Student> &db)
{
    std::vector<std::pair<double, std::string>> averages;

    for (auto &[marks, name] : db)
    {
        double avg = std::accumulate(marks.begin(), marks.end(), 0.0) / marks.size();
        averages.push_back({avg, name});
    }
    return averages;
}

int
main()
{
    const std::vector<Student> db{
        {{5.0, 5.0, 5.0, 4.0}, "John"},
        {{6.0, 4.0, 7.0, 1.0}, "Mark"},
        {{2.0, 3.0, 7.0, 3.0}, "Jane"},
    };

    auto averages = ComputeAverages(db);

    for (const auto &[avg, name] : averages)
    {
        std::cout << name << ": " << avg << '\n';
    }
}

// John: 4.75
// Mark: 4.5
// Jane: 3.75
