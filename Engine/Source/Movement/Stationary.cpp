#include <GeoCore/Movement/Stationary.hpp>

#include <GeoCore/Math/Distance.hpp>
#include <GeoCore/Tracking/Duration.hpp>

namespace GeoCore::Movement
{

bool stationary(
    const Track& track,
    double maximumRadiusMeters,
    std::chrono::seconds minimumDuration)
{
    if (track.size() < 2)
    {
        return false;
    }

    const auto elapsed =
        Tracking::duration(track);

    if (elapsed < minimumDuration)
    {
        return false;
    }

    const double traveled =
        Math::distance(
            track.front().position(),
            track.back().position());

    return traveled <= maximumRadiusMeters;
}

} // namespace GeoCore::Movement