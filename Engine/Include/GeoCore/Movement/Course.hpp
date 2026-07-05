#pragma once

#include <GeoCore/PositionSample.hpp>

namespace GeoCore::Movement
{

[[nodiscard]]
double course(
    const PositionSample& previous,
    const PositionSample& current);

} // namespace GeoCore::Movement