#include <variant>

struct Circle
{
    void
    Draw() const
    {
    }
};

struct Square
{
    void
    Draw() const
    {
    }
};

struct Triangle
{
    void
    Draw() const
    {
    }
};

int
main()
{
    std::variant<Circle, Square, Triangle> shape;
    shape               = Triangle{};
    const auto callDraw = [](auto &sh) { sh.Draw(); };
    std::visit(callDraw, shape);
}
