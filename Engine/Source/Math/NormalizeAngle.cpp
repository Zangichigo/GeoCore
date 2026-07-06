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

    return angle;
}

} // namespace GeoCore::Math