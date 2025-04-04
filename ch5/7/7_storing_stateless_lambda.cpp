// Default Constructible Lambdas

template <typename F>
struct Product
{
    int    id{0};
    double price{0.0};
    F      predicate;
};

int
main()
{
    const auto idCmp = [](const auto &a) noexcept { return a.id != 0; };

    Product p{10, 10.0, idCmp};   // can store stateless lambdas

    [[maybe_unused]] auto p2 = p; // can copy stateless lambdas
}
