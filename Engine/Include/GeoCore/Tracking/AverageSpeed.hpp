#pragma once

#include <GeoCore/Track.hpp>

namespace GeoCore::Tracking
{

[[nodiscard]]
double averageSpeed(const Track& track);

} // namespace GeoCore::Tracking