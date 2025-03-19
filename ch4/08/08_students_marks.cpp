#include <iostream>
#include <numeric>
#include <vector>

int
main()
{
    using Student = std::pair<std::vector<double>, std::string>;
    const std::vector<Student> db{
        {{5.0, 5.0, 5.0, 4.0}, "John"}, {{5.0, 5.0, 5.0, 4.0}, "Mark"}, {{5.0, 5.0, 5.0, 4.0}, "Jane"}};

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
