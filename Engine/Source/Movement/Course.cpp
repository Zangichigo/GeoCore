#include <GeoCore/Movement/Course.hpp>

#include <GeoCore/Math/Bearing.hpp>

namespace GeoCore::Movement
{

double course(
    const PositionSample& previous,
    const PositionSample& current)
{
    return Math::bearing(
        previous.position(),
        current.position());
}

} // namespace GeoCore::Movement