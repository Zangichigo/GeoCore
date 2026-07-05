#pragma once

#include <GeoCore/PositionSample.hpp>

namespace GeoCore::Movement
{

[[nodiscard]]
double acceleration(
    const PositionSample& previous,
    const PositionSample& current,
    const PositionSample& next);

} // namespace GeoCore::Movement