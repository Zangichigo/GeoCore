#pragma once

#include <GeoCore/Track.hpp>

#include <chrono>

namespace GeoCore::Movement
{

[[nodiscard]]
bool stationary(
    const Track& track,
    double maximumRadiusMeters,
    std::chrono::seconds minimumDuration);

} // namespace GeoCore::Movement