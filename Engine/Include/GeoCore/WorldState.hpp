#pragma once

#include <GeoCore/Position.hpp>

namespace GeoCore
{
    class WorldState
    {
    public:
        explicit WorldState(Position position);

        const Position& position() const noexcept;

    private:
        Position position_;
    };
}