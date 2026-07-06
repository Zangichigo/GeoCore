#include <GeoCore/Math/AngularDifference.hpp>

#include <GeoCore/Math/NormalizeSignedAngle.hpp>

namespace GeoCore::Math
{

double angularDifference(
    double angle1,
    double angle2)
{
    return normalizeSignedAngle(angle2 - angle1);
}

} // namespace GeoCore::Math