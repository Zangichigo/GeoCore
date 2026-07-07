#include <GeoCore/Math/CircularRange.hpp>

#include <GeoCore/Math/NormalizeAngle.hpp>

#include <algorithm>
#include <vector>

namespace GeoCore::Math
{

double circularRange(std::span<const double> angles)
{
    if (angles.size() <= 1)
    {
        return 0.0;
    }

    std::vector<double> sorted;
    sorted.reserve(angles.size());

    for (double angle : angles)
    {
        sorted.push_back(normalizeAngle(angle));
    }

    std::sort(sorted.begin(), sorted.end());

    double largestGap = 0.0;

    for (std::size_t i = 0; i + 1 < sorted.size(); ++i)
    {
        largestGap = std::max(
            largestGap,
            sorted[i + 1] - sorted[i]);
    }

    // Wraparound gap
    largestGap = std::max(
        largestGap,
        (sorted.front() + 360.0) - sorted.back());

    return 360.0 - largestGap;
}

} // namespace GeoCore::Math