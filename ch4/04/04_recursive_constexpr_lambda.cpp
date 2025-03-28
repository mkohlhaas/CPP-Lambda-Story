#include <iostream>

int
main()
{
    // also conexpressable now
    constexpr auto factorial = [](int n) {
        constexpr auto fact_impl = [](int n, const auto &impl) -> int { return n > 1 ? n * impl(n - 1, impl) : 1; };
        return fact_impl(n, fact_impl);
    };

    static_assert(factorial(5) == 120);

    std::cout << factorial(5) << '\n'; // 120
}
