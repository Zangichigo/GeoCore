#include <GeoCore/Polygon.hpp>

#include <cstddef>
#include <utility>

namespace GeoCore
{

Polygon::Polygon(std::vector<Position> vertices)
    : vertices_(std::move(vertices))
{
}

bool Polygon::contains(const Position& position) const
{
    if (vertices_.size() < 3)
    {
        return false;
    }

    bool inside = false;

    const std::size_t vertexCount = vertices_.size();

    for (std::size_t i = 0, j = vertexCount - 1;
         i < vertexCount;
         j = i++)
    {
        const Position& current = vertices_[i];
        const Position& previous = vertices_[j];

        const bool intersects =
            ((current.latitude() > position.latitude()) !=
             (previous.latitude() > position.latitude()));

        if (intersects)
        {
            const double intersectionLongitude =
                previous.longitude() +
                (current.longitude() - previous.longitude()) *
                (position.latitude() - previous.latitude()) /
                (current.latitude() - previous.latitude());

            if (position.longitude() < intersectionLongitude)
            {
                inside = !inside;
            }
        }
    }

    return inside;
}
}