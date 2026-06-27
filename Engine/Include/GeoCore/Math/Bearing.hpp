#pragma once

#include <GeoCore/Position.hpp>

namespace GeoCore::Math
{

/// Computes the initial bearing (forward azimuth) from one position to another.
/// The returned angle is expressed in degrees in the range [0°, 360°).
double bearing(
    const Position& from,
    const Position& to);

} // namespace GeoCore::Math