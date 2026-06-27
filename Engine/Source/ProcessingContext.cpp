#include <GeoCore/ProcessingContext.hpp>

namespace GeoCore
{

ProcessingContext::ProcessingContext(const WorldState& worldState)
    : worldState_(worldState)
{
}

const WorldState& ProcessingContext::worldState() const noexcept
{
    return worldState_;
}

}