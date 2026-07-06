#include <GeoCore/Movement/CourseAnalysis.hpp>

#include <GeoCore/Movement/CourseSeries.hpp>

#include <algorithm>


namespace GeoCore::Movement
{

CourseAnalysis::CourseAnalysis(
    double minimum,
    double maximum,
    double range)
    : m_minimum(minimum)
    , m_maximum(maximum)
    , m_range(range)
{
}

double CourseAnalysis::minimum() const noexcept
{
    return m_minimum;
}

double CourseAnalysis::maximum() const noexcept
{
    return m_maximum;
}

double CourseAnalysis::range() const noexcept
{
    return m_range;
}

CourseAnalysis courseAnalysis(
    const CourseSeries& series)
{
    if (series.empty())
    {
        return CourseAnalysis(
            0.0,
            0.0,
            0.0);
    }

    const auto& values = series.values();

    const auto min =
        *std::min_element(
            values.begin(),
            values.end());

    const auto max =
        *std::max_element(
            values.begin(),
            values.end());

    return CourseAnalysis(
        min,
        max,
        max - min);
}

} // namespace GeoCore::Movement