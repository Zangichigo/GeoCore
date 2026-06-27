#include <GeoCore/PositionSample.hpp>

#include <utility>

namespace GeoCore
{

PositionSample::PositionSample(
    Position position,
    std::chrono::system_clock::time_point timestamp)
    : position_(std::move(position))
    , timestamp_(timestamp)
{
}

const Position& PositionSample::position() const noexcept
{
    return position_;
}

std::chrono::system_clock::time_point
PositionSample::timestamp() const noexcept
{
    return timestamp_;
}

} // namespace GeoCore