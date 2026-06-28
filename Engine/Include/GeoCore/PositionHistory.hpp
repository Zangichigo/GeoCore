#pragma once

#include <GeoCore/PositionSample.hpp>

#include <vector>

#include <cstddef>

namespace GeoCore
{

class PositionHistory
{
public:
    void push_back(PositionSample sample);

    const PositionSample& front() const;

    const PositionSample& back() const;

    bool empty() const noexcept;

    std::size_t size() const noexcept;

private:
    std::vector<PositionSample> samples_;
};

} // namespace GeoCore