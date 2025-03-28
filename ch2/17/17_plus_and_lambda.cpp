#include <type_traits>

int
main()
{
    // + is a unary operator that can work on pointers.
    // So the compiler converts the stateless lambda into a function pointer!
    auto funcPtr1 = +[] {};
    auto funcPtr2 = static_cast<void (*)()>([] {}); // explicit conversion

    static_assert(std::is_same_v<decltype(funcPtr1), void (*)()>);
    static_assert(std::is_same_v<decltype(funcPtr2), void (*)()>);
}
