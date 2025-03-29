#include <future>
#include <iostream>
#include <numeric>
#include <vector>

// std::future is an object which handles the synchronisation
// and guarantees that the results of the invocation are
// available when we ask for it through .get().

// It seems that over the years std::async/std::future has earned itself a mixed reputation.
// It looks like the functionality was a bit too rushed. It works for relatively simple cases but
// fails with advanced scenarios like:
// - continuation
// - task merging
// - no cancellation/joining
// - it’s not a regular type
// - and few other issues

int
main()
{
    const auto printThreadID = [](const char *str) {
        std::cout << str << ": " << std::this_thread::get_id() << " thread id\n";
    };

    std::vector<int> numbers(100);

    std::future<void> iotaFuture = std::async(std::launch::async,                                      //
                                              [&numbers, startArg = 10, &printThreadID]() {            //
                                                  std::iota(numbers.begin(), numbers.end(), startArg); //
                                                  printThreadID("iota in");                            //
                                              });

    iotaFuture.get(); // make sure we get the results...
    printThreadID("printing numbers in");

    for (const auto &num : numbers)
    {
        std::cout << num << ", ";
    }
}
