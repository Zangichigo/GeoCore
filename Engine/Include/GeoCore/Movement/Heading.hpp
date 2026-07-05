#pragma once

#include <GeoCore/PositionSample.hpp>

namespace GeoCore::Movement
{
    double heading(
        const PositionSample& from,
        const PositionSample& to);
}