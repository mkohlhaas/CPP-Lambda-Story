#include <iostream>
#include <thread>
#include <vector>

int
main()
{
    // shared variable
    int counter = 0;

    const auto maxThreads = std::thread::hardware_concurrency();

    std::cout << "Max threads: " << maxThreads << '\n';

    std::vector<std::thread> threads;
    threads.reserve(maxThreads);
    for (size_t tCounter = 0; tCounter < maxThreads; ++tCounter)
    {
        threads.push_back(std::thread([&counter]() noexcept {
            for (int i = 0; i < 10000; ++i)
            {
                ++counter;
            }
        }));
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    std::cout << counter << '\n'; // 29237 [not 40000]
}
