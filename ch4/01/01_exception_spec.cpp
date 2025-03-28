using TVoidFunc         = void (*)();
using TVoidFuncNoexcept = void (*)() noexcept;

void
SimpleNoexceptCall(TVoidFuncNoexcept f)
{
    f();
}

// can take except and noexcept functions
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
