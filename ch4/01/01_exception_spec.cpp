using TNoexceptVoidFunc = void (*)() noexcept;
void
SimpleNoexceptCall(TNoexceptVoidFunc f)
{
    f();
}

using TVoidFunc = void (*)();
void
SimpleCall(TVoidFunc f)
{
    f();
}

void
fNoexcept() noexcept
{
}
void
fRegular()
{
}

int
main()
{
    SimpleNoexceptCall(fNoexcept);
    SimpleNoexceptCall([]() noexcept {});
    // SimpleNoexceptCall(fRegular);   // cannot convert
    // SimpleNoexceptCall([]() { });  // cannot convert

    SimpleCall(fNoexcept);        // converts to regular function
    SimpleCall(fRegular);
    SimpleCall([]() noexcept {}); // converts
    SimpleCall([]() {});
}
