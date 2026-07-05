#pragma once

#include <GeoCore/Track.hpp>

#include <chrono>

namespace GeoCore::Tracking
{

[[nodiscard]]
std::chrono::system_clock::duration duration(const Track& track);

} // namespace GeoCore::Tracking