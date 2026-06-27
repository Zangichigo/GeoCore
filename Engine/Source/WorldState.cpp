#include <GeoCore/WorldState.hpp>

namespace GeoCore
{

WorldState::WorldState(Position position)
    : position_(position)
{
}

const Position& WorldState::position() const noexcept
{
    return position_;
}

}