#include <GeoCore/Circle.hpp>

namespace GeoCore
{

Circle::Circle(Position center, double radius)
    : center_(center),
      radius_(radius)
{
}

bool Circle::contains(const Position& position) const
{
    (void)position;

    return false;
}

}