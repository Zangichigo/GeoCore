#pragma once

#include <GeoCore/Position.hpp>

#include <chrono>

namespace GeoCore
{

class PositionSample
{
public:
    PositionSample(
        Position position,
        std::chrono::system_clock::time_point timestamp);

    const Position& position() const noexcept;

    std::chrono::system_clock::time_point timestamp() const noexcept;

private:
    Position position_;
    std::chrono::system_clock::time_point timestamp_;
};

} // namespace GeoCore