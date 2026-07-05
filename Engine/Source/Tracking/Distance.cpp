#include <GeoCore/Tracking/Distance.hpp>

#include <GeoCore/Math/Distance.hpp>

namespace GeoCore::Tracking
{

double distance(const Track& track)
{
    if (track.size() < 2)
    {
        return 0.0;
    }

    double totalDistance = 0.0;

    for (std::size_t i = 1; i < track.size(); ++i)
    {
        totalDistance += Math::distance(
            track[i - 1].position(),
            track[i].position());
    }

    return totalDistance;
}

}