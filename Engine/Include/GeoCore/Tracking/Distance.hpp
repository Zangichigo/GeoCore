#pragma once

#include <GeoCore/Track.hpp>

namespace GeoCore::Tracking
{
    [[nodiscard]]
    double distance(const Track& track);
}