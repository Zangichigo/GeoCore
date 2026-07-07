#pragma once

namespace GeoCore::Movement
{

class CourseSeries;

class CourseAnalysis
{
public:
    [[nodiscard]]
    static CourseAnalysis fromSeries(
        const CourseSeries& series);

    [[nodiscard]]
    double mean() const noexcept;

private:
    explicit CourseAnalysis(
        double mean);

    double m_mean;
};

} // namespace GeoCore::Movement