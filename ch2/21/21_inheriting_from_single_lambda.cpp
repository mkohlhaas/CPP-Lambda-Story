#include <iostream>

template <typename Callable>
class ComplexFn : public Callable
{
  public:
    explicit ComplexFn(Callable f) : Callable(f)
    {
    }
};

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
