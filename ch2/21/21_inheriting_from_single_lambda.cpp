#include <iostream>

// Inheriting from a Lambda
//
// Since the compiler expands a lambda expression into a function object with operator(),
// then we can inherit from this type.
//
// If we want to derive from a lambda, we need to do a little trick,
// as we cannot spell out the exact type of the closure type - unless we
// wrap it into a std::function.

template <typename Callable>
class ComplexFn : public Callable
{
  public:
    explicit ComplexFn(Callable f) : Callable(f)
    {
    }
};

// This function template is used for let the compiler deduce the
// type of the passed lambda function. The type is a class (function object)
// with operator().
template <typename Callable>
ComplexFn<Callable>
makeComplexFunctionObject(Callable &&cal)
{
    return ComplexFn<Callable>(std::forward<Callable>(cal));
}

int
main()
{
    const auto func = makeComplexFunctionObject([]() { std::cout << "Hello Complex Function Object!"; });
    func(); // Hello Complex Function Object!
}
