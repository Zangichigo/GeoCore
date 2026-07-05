#include <GeoCore/Tracking/Duration.hpp>

namespace GeoCore::Tracking
{

std::chrono::system_clock::duration duration(const Track& track)
{
    if (track.size() < 2)
    {
        return std::chrono::system_clock::duration::zero();
    }

    return track.back().timestamp() - track.front().timestamp();
}

} // namespace GeoCore::Tracking