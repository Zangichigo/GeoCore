#pragma once

#include <vector>

#include <GeoCore/ProcessingResult.hpp>
#include <GeoCore/WorldState.hpp>
#include <GeoCore/Zone.hpp>

namespace GeoCore
{
    class Engine
    {
    public:
        Engine();

        void addZone(Zone zone);

        ProcessingResult process(const WorldState& worldState);

    private:
        std::vector<Zone> zones_;
    };
}