#include <iostream>
#include <memory>

// cp. ../ch2/12/12_capturing_a_variadic_pack.cpp
// cp. ../ch4/12/12_printing_elements_without.cpp

template <class First, class... Args>
void
captureTest(First &&first, Args &&...args)
{
    //                                             pack expansion in lambda init-capture
    //                                              ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    const auto printer = [first = std::move(first), ... capturedArgs = std::move(args)] {
        std::cout << first;
        ((std::cout << ", " << capturedArgs), ...);
        std::cout << '\n';
    };
    printer();
}

int
main()
{
    auto ptr = std::make_unique<int>(10);

    captureTest(std::move(ptr), 2, 3, 4);  // 0x586b3750e2b0, 2, 3, 4
    captureTest(std::move(ptr), 'a', 'b'); // 0, a, b
}
