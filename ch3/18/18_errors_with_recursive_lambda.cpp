// this doesn't compile, intentionally
int
main()
{
    auto factorial = [](int n) { return n > 1 ? n * factorial(n - 1) : 1; };
    return factorial(5);
}
