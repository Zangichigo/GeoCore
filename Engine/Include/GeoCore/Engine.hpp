#pragma once

#include <GeoCore/WorldState.hpp>

namespace GeoCore
{
    class Engine
    {
    public:
        Engine();

        void process(const WorldState& worldState);
    };
}