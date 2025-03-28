#include <type_traits>

int
main()
{
    auto funcPtr = +[] {};

    static_assert(std::is_same_v<decltype(funcPtr), void (*)()>);
}
