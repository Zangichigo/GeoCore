#include <GeoCore/Track.hpp>

namespace GeoCore
{

void Track::push_back(const PositionSample& sample)
{
    samples_.push_back(sample);
}

bool Track::empty() const
{
    return samples_.empty();
}

std::size_t Track::size() const
{
    return samples_.size();
}

const PositionSample& Track::front() const
{
    return samples_.front();
}

const PositionSample& Track::back() const
{
    return samples_.back();
}

const PositionSample& Track::operator[](std::size_t index) const
{
    return samples_[index];
}

const std::vector<PositionSample>& Track::samples() const
{
    return samples_;
}

void Track::add(const PositionSample& sample)
{
    push_back(sample);
}

const PositionSample& Track::first() const
{
    return front();
}

const PositionSample& Track::last() const
{
    return back();
}

} // namespace GeoCore