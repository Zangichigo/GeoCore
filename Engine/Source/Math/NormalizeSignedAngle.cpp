#include <GeoCore/Math/NormalizeSignedAngle.hpp>

#include <GeoCore/Math/NormalizeAngle.hpp>

namespace GeoCore::Math
{

double normalizeSignedAngle(double angle)
{
    angle = normalizeAngle(angle);

    if (angle > 180.0)
    {
        angle -= 360.0;
    }

    return angle;
}

} // namespace GeoCore::Math