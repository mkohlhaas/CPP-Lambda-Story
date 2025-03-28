#include <iostream>
#include <numeric>
#include <vector>

int
main()
{
    using Student = std::pair<std::vector<double>, std::string>;
    const std::vector<Student> db{
        {{5.0, 5.0, 5.0, 4.0}, "John"},
        {{6.0, 4.0, 7.0, 1.0}, "Mark"},
        {{2.0, 3.0, 7.0, 3.0}, "Jane"},
    };

    std::vector<std::pair<double, std::string>> averages;

    for (auto &[marks, name] : db)
    {
        double avg = std::accumulate(marks.begin(), marks.end(), 0.0) / marks.size();
        averages.push_back({avg, name});
    }

    for (const auto &[avg, name] : averages)
    {
        std::cout << name << ": " << avg << '\n';
    }
}

// John: 4.75
// Mark: 4.5
// Jane: 3.75
