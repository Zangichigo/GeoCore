#include <GeoCore/Math/NormalizeAngle.hpp>

#include <cmath>

namespace GeoCore::Math
{

double normalizeAngle(double angle)
{
    angle = std::fmod(angle, 360.0);

    if (angle < 0.0)
    {
        angle += 360.0;
    }

constexpr double epsilon = 1e-12;

if (std::abs(angle) < epsilon)
{
    return 0.0;
}

if (std::abs(angle - 360.0) < epsilon)
{
    return 0.0;
}

    return angle;
}

} // namespace GeoCore::Math