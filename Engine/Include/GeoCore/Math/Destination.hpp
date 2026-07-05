#pragma once

#include <GeoCore/Position.hpp>

namespace GeoCore::Math
{

[[nodiscard]]
Position destination(
    const Position& start,
    double bearingDegrees,
    double distanceMeters);

}