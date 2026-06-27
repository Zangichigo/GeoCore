#include <GeoCore/Engine.hpp>

namespace GeoCore
{

Engine::Engine() = default;

void Engine::process(const WorldState& worldState)
{
    (void)worldState;
}

}