#include <iostream>
#include <memory>

int
main()
{
    std::unique_ptr<int> p(new int{10});
    std::cout << "pointer in main(): " << p.get() << '\n'; // pointer in main(): 0x62e40745e2b0

    const auto bar = [ptr = std::move(p)] { std::cout << "pointer in lambda: " << ptr.get() << '\n'; };

    std::cout << "pointer in main(): " << p.get() << '\n'; // pointer in main(): 0
    bar();                                                 // pointer in lambda: 0x5662402ed2b0
}
