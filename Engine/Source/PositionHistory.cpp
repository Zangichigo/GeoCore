#include <GeoCore/PositionHistory.hpp>

#include <utility>

namespace GeoCore
{

void PositionHistory::push_back(PositionSample sample)
{
    samples_.push_back(std::move(sample));
}

const PositionSample& PositionHistory::front() const
{
    return samples_.front();
}

const PositionSample& PositionHistory::back() const
{
    return samples_.back();
}

bool PositionHistory::empty() const noexcept
{
    return samples_.empty();
}

std::size_t PositionHistory::size() const noexcept
{
    return samples_.size();
}

} // namespace GeoCore