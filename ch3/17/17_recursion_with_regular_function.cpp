int
factorial(int n)
{
    return n > 1 ? n * factorial(n - 1) : 1;
}

int
main()
{
    return factorial(5);
}
