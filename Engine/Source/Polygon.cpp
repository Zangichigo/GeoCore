#include <GeoCore/Polygon.hpp>
#include <utility>

namespace GeoCore
{

Polygon::Polygon(std::vector<Position> vertices)
    : vertices_(std::move(vertices))
{
}

bool Polygon::contains(const Position& position) const
{
    (void)position;

    return false;
}

}