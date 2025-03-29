using TVoidFunc         = void (*)();
using TVoidFuncNoexcept = void (*)() noexcept;

// A pointer to a noexcept function can be converted to a pointer to a regular function.
// But not the other way around.

// takes only noexcept functions
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

    // SimpleNoexceptCall(fRegular);  // cannot convert
    // SimpleNoexceptCall([]() { });  // cannot convert

    SimpleCall(fNoexcept);        // converts to regular function
    SimpleCall(fRegular);
    SimpleCall([]() noexcept {}); // converts
    SimpleCall([]() {});
}
