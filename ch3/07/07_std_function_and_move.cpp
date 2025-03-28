#include <functional>
#include <memory>

int
main()
{
    std::unique_ptr<int> p(new int{10});

    // std::function accepts only copyable callable objects but unique pointer is movable-only.
    std::function<void()> func = [ptr = std::move(p)]() {}; // won't compile
}
