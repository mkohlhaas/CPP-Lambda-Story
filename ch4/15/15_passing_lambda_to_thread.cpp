#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

// Concurrent Execution Using Lambdas
//
// calling a lambda on a separate thread

int
main()
{
    std::cout << "Main thread: " << std::this_thread::get_id() << " thread id\n";

    const auto printThreadID = [](const char *str) {
        std::cout << str << ": " << std::this_thread::get_id() << " thread id\n";
    };

    std::vector<int> numbers(100);

    {
        // start another thread
        std::thread iotaThread(
            [&numbers, &printThreadID](int startArg) {
                std::iota(numbers.begin(), numbers.end(), startArg);
                printThreadID("iota in");
            },
            10);

        iotaThread.join();
    }

    {
        // in main thread
        printThreadID("printing numbers in");

        for (const auto &num : numbers)
        {
            std::cout << num << ", ";
        }
    }
}

// iota in: 137806289655488 thread id
// printing numbers in: 137806296331840 thread id
// 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
// 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
// 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95 , 96,
// 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
