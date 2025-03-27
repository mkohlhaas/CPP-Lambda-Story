#include <type_traits>

int
main()
{
    const auto firstLam  = [](int x) noexcept { return x * 2; };
    const auto secondLam = firstLam;
    static_assert(std::is_same_v<decltype(firstLam), decltype(secondLam)>, "must be the same");
}
