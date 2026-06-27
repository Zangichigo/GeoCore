#include <GeoCore/Circle.hpp>
#include <GeoCore/Math/Distance.hpp>

namespace GeoCore
{

Circle::Circle(Position center, double radius)
    : center_(center),
      radius_(radius)
{
}

bool Circle::contains(const Position& position) const
{
    return Math::distance(center_, position) <= radius_;
}

} // namespace GeoCore