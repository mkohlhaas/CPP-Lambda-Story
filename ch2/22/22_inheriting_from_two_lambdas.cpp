#include <iostream>

template <typename TCall, typename UCall>
class SimpleOverloaded : public TCall, UCall
{
  public:
    SimpleOverloaded(TCall tf, UCall uf) : TCall(tf), UCall(uf)
    {
    }

    using TCall::operator();
    using UCall::operator();
};

// deduce the types of the lambdas
template <typename TCall, typename UCall>
SimpleOverloaded<TCall, UCall>
MakeOverloaded(TCall &&tf, UCall &&uf)
{
    return SimpleOverloaded<TCall, UCall>(std::forward<TCall>(tf), std::forward<UCall>(uf));
}

int
main()
{
    const auto func = MakeOverloaded([](int) { std::cout << "Int!\n"; }, [](float) { std::cout << "Float!\n"; });
    func(10);    // Int!
    func(10.0f); // Float!
}
