#include <iostream>

void
callWith10(void (*fn)(int))
{
    fn(10);
}

int
main()
{
    // [1]
    {
        callWith10([](int x) { std::cout << x << '\n'; }); // 10
    }

    // [2] (this happens underneath)
    {
        struct
        {
            // void
            // operator()(int s) const
            // {
            //     return call(s);
            // }

            using f_ptr = void (*)(int);

            operator f_ptr() const
            {
                return &call;
            }

          private:
            static void
            call(int s)
            {
                std::cout << s << '\n';
            };
        } baz;

        callWith10(baz); // 10
    }
}
