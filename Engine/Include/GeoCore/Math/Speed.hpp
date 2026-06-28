#pragma once

#include <GeoCore/PositionSample.hpp>

namespace GeoCore::Math
{

double speed(
    const PositionSample& from,
    const PositionSample& to);

} // namespace GeoCore::Math