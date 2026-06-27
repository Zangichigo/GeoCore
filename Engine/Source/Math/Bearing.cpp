#include <GeoCore/Math/Bearing.hpp>
#include <GeoCore/Math/MathUtils.hpp>

#include <cmath>

namespace GeoCore::Math
{

double bearing(
    const Position& from,
    const Position& to)
{
    const double latitude1 = toRadians(from.latitude());
    const double latitude2 = toRadians(to.latitude());

    const double deltaLongitude =
        toRadians(to.longitude() - from.longitude());

    const double y =
        std::sin(deltaLongitude) * std::cos(latitude2);

    const double x =
        std::cos(latitude1) * std::sin(latitude2) -
        std::sin(latitude1) * std::cos(latitude2) *
        std::cos(deltaLongitude);

    double angle = toDegrees(std::atan2(y, x));

    if (angle < 0.0)
    {
        angle += 360.0;
    }

    return angle;
}

} // namespace GeoCore::Math