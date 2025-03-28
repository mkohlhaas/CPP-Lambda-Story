#include <iostream>
#include <vector>

// Storing Lambdas in a Container

// You cannot store closure objects directly, but you can save function
// pointers converted from lambda expressions.

int
main()
{
    using TFunc = void (*)(int &);

    std::vector<TFunc> ptrFuncVec;

    ptrFuncVec.push_back([](int &x) { std::cout << x << '\n'; });
    ptrFuncVec.push_back([](int &x) { x *= 2; });
    ptrFuncVec.push_back(ptrFuncVec[0]);

    int x = 10;
    for (const auto &entry : ptrFuncVec)
    {
        entry(x); // 10 20
    }
}
