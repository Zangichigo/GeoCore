#include <GeoCore/Engine.hpp>

#include <utility>

namespace GeoCore
{

Engine::Engine() = default;

void Engine::addZone(Zone zone)
{
    zones_.push_back(std::move(zone));
}

ProcessingResult Engine::process(const WorldState& worldState)
{
    for (const auto& zone : zones_)
    {
        if (zone.contains(worldState.position()))
        {
            return ProcessingResult(ZoneMembership::Inside);
        }
    }

    return ProcessingResult(ZoneMembership::Outside);;
}

}