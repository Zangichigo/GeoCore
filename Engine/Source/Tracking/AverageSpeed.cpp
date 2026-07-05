#include <GeoCore/Tracking/AverageSpeed.hpp>

#include <GeoCore/Tracking/Distance.hpp>
#include <GeoCore/Tracking/Duration.hpp>

#include <chrono>

namespace GeoCore::Tracking
{

double averageSpeed(const Track& track)
{
    const double totalDistance =
        Tracking::distance(track);

    const auto totalDuration =
        Tracking::duration(track);

    const double seconds =
        std::chrono::duration<double>(totalDuration).count();

    if (seconds <= 0.0)
    {
        return 0.0;
    }

    return totalDistance / seconds;
}

} // namespace GeoCore::Tracking