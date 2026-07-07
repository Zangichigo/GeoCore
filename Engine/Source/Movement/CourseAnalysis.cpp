#include <GeoCore/Movement/CourseAnalysis.hpp>

#include <GeoCore/Movement/CourseSeries.hpp>

#include <GeoCore/Math/CircularMean.hpp>

namespace GeoCore::Movement
{

CourseAnalysis::CourseAnalysis(
    double mean)
    : m_mean(mean)
{
}

double CourseAnalysis::mean() const noexcept
{
    return m_mean;
}

CourseAnalysis CourseAnalysis::fromSeries(
    const CourseSeries& series)
{
    if (series.empty())
    {
        return CourseAnalysis(0.0);
    }

    return CourseAnalysis(
        GeoCore::Math::circularMean(
            series.values()));
}

} // namespace GeoCore::Movement