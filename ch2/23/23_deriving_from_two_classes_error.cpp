#include <iostream>
#include <vector>

int
main()
{
    using TFunc = void (*)(int &);
    std::vector<TFunc> ptrFuncVec;

    ptrFuncVec.push_back([](int &x) { std::cout << x << '\n'; });
    ptrFuncVec.push_back([](int &x) { x *= 2; });
    ptrFuncVec.push_back(ptrFuncVec[0]); // print it again;

    int x = 10;
    for (const auto &entry : ptrFuncVec)
    {
        entry(x);
    }
}
