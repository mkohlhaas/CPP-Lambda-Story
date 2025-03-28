#include <type_traits>

int
main()
{
    const auto baz = [](int x) noexcept {
        if (x < 20)
        {
            return x * 1.1;
        }
        else
        {
            return x * 2.1;
        }
    };

    static_assert(std::is_same_v<double, decltype(baz(10))>, "has to be the same!");
}
