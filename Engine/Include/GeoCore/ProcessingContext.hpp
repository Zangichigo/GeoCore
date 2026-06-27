#pragma once

#include <GeoCore/WorldState.hpp>

namespace GeoCore
{

class ProcessingContext
{
public:
    explicit ProcessingContext(const WorldState& worldState);

    const WorldState& worldState() const noexcept;

private:
    const WorldState& worldState_;
};

}