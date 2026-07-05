#include <GeoCore/Rectangle.hpp>

namespace GeoCore
{

Rectangle::Rectangle(
    const Position& southWest,
    const Position& northEast)
    :
    southWest_(southWest),
    northEast_(northEast)
{
}

bool Rectangle::contains(
    const Position& position) const
{
    return
        position.latitude() >= southWest_.latitude() &&
        position.latitude() <= northEast_.latitude() &&
        position.longitude() >= southWest_.longitude() &&
        position.longitude() <= northEast_.longitude();
}

const Position& Rectangle::southWest() const
{
    return southWest_;
}

const Position& Rectangle::northEast() const
{
    return northEast_;
}

}