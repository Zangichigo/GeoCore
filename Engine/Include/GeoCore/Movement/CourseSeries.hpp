#pragma once

#include <cstddef>
#include <vector>

namespace GeoCore
{
class Track;
}

namespace GeoCore::Movement
{

class CourseSeries
{
public:

    [[nodiscard]]
    bool empty() const noexcept;

    [[nodiscard]]
    std::size_t size() const noexcept;

    [[nodiscard]]
    double operator[](std::size_t index) const;

    [[nodiscard]]
    const std::vector<double>& values() const noexcept;

private:

    explicit CourseSeries(std::vector<double> courses);

    std::vector<double> m_courses;

    friend CourseSeries courseSeries(const Track& track);
};

[[nodiscard]]
CourseSeries courseSeries(const Track& track);

} // namespace GeoCore::Movement