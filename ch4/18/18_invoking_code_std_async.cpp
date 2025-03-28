#include <future>
#include <iostream>
#include <numeric>
#include <vector>

int
main()
{
    const auto printThreadID = [](const char *str) {
        std::cout << str << ": " << std::this_thread::get_id() << " thread id\n";
    };

    std::vector<int> numbers(100);

    std::future<void> iotaFuture = std::async(std::launch::async, [&numbers, startArg = 10, &printThreadID]() {
        std::iota(numbers.begin(), numbers.end(), startArg);
        printThreadID("iota in");
    });

    iotaFuture.get(); // make sure we get the results...
    printThreadID("printing numbers in");

    for (const auto &num : numbers)
    {
        std::cout << num << ", ";
    }
}
