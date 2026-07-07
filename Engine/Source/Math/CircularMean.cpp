#include <GeoCore/Math/CircularMean.hpp>

#include <GeoCore/Math/NormalizeAngle.hpp>

#include <cmath>
#include <numbers>

namespace GeoCore::Math
{

double circularMean(
    std::span<const double> angles)
{
    if (angles.empty())
    {
        return 0.0;
    }

    double sumSin = 0.0;
    double sumCos = 0.0;

    for (double angle : angles)
    {
        angle = normalizeAngle(angle);

        const double radians =
            angle * std::numbers::pi / 180.0;

        sumSin += std::sin(radians);
        sumCos += std::cos(radians);
    }

    const double meanRadians =
        std::atan2(sumSin, sumCos);

    const double meanDegrees =
        meanRadians * 180.0 / std::numbers::pi;

    return normalizeAngle(meanDegrees);
}

} // namespace GeoCore::Math