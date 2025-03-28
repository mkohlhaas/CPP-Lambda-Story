#include <iostream>
#include <type_traits>

template <typename Callable>
void
CallWith22(Callable &&fn)
{
    if constexpr (std::is_nothrow_invocable_v<Callable, int>)
    {
        std::cout << "Calling fn(22) with optimisation\n";
        fn(22);
    }
    else
    {
        std::cout << "Calling fn(22) normally\n";
        fn(22);
    }
}

int
main()
{
    int x{11};

    const auto lam = [&x](int y) noexcept { x += y; };
    CallWith22(lam);        // Calling fn(22) with optimisation

    std::cout << x << '\n'; // 33

    const auto lamEx = [&x](int y) { x += y; };

    CallWith22(lamEx);      // Calling fn(22) normally

    std::cout << x << '\n'; // 55
}
