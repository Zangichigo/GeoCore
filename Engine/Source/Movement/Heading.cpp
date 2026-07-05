#include <GeoCore/Movement/Heading.hpp>

#include <GeoCore/Math/Bearing.hpp>

namespace GeoCore::Movement
{
    double heading(
        const PositionSample& from,
        const PositionSample& to)
    {
        return Math::bearing(
            from.position(),
            to.position());
    }
}