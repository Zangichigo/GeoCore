#pragma once

#include <GeoCore/PositionSample.hpp>

#include <cstddef>
#include <vector>

namespace GeoCore
{

class Track
{
public:

    void push_back(const PositionSample& sample);

    [[nodiscard]]
    bool empty() const;

    [[nodiscard]]
    std::size_t size() const;

    [[nodiscard]]
    const PositionSample& front() const;

    [[nodiscard]]
    const PositionSample& back() const;

    [[nodiscard]]
    const PositionSample& operator[](std::size_t index) const;

    [[nodiscard]]
    const std::vector<PositionSample>& samples() const;

    [[nodiscard]]
    const PositionSample& first() const;

    [[nodiscard]]
    const PositionSample& last() const;

void add(const PositionSample& sample);

private:

    std::vector<PositionSample> samples_;

};

} // namespace GeoCore