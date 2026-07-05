#include <GeoCore/Math/Midpoint.hpp>

namespace GeoCore::Math
{

Position midpoint(
    const Position& first,
    const Position& second)
{
    return Position(
        (first.latitude() + second.latitude()) / 2.0,
        (first.longitude() + second.longitude()) / 2.0);
}

}