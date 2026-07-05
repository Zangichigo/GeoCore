#pragma once

#include <GeoCore/Position.hpp>

namespace GeoCore::Math
{
    [[nodiscard]]
    Position midpoint(
        const Position& first,
        const Position& second);
}