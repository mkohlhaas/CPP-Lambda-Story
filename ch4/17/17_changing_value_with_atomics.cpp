#include <iostream>
#include <thread>
#include <vector>

int
main()
{
    std::atomic<int> counter = 0;

    const auto maxThreads = std::thread::hardware_concurrency();
    std::cout << "Max threads: " << maxThreads << '\n'; // 4

    std::vector<std::thread> threads;
    threads.reserve(maxThreads);

    for (size_t tCounter = 0; tCounter < maxThreads; ++tCounter)
    {
        threads.push_back(std::thread([&counter]() noexcept {
            for (int i = 0; i < 10000; ++i)
            {
                counter.fetch_add(1);
            }
        }));
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    std::cout << counter.load() << '\n'; // 40000
}
