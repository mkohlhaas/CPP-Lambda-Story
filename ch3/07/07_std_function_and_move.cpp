#include <functional>
#include <memory>

int
main()
{
    std::unique_ptr<int>  p(new int{10});
    std::function<void()> func = [ptr = std::move(p)]() {}; // won't compile
}
