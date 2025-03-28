#include <iostream>

int
main()
{
    // using an internal lambda
    const auto factorial = [](int n) noexcept {
        const auto f_impl = [](int n, const auto &impl) noexcept -> int //
        { return n > 1 ? n * impl(n - 1, impl) : 1; };                  //

        return f_impl(n, f_impl);
    };

    std::cout << factorial(5) << '\n';
}
