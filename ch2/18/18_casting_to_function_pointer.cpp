template <typename F>
void
call_function(F f)
{
    f(10);
}

int
main()
{
    auto plus = [](int x) { return x + 2; }; // int -> int
    auto mult = [](int x) { return x * 2; }; // int -> int

    call_function(plus);
    call_function(mult);

    call_function(static_cast<int (*)(int)>(plus));
    call_function(static_cast<int (*)(int)>(mult));
}
