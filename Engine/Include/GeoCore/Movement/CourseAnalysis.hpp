#pragma once

namespace GeoCore::Movement
{

class CourseSeries;

class CourseAnalysis
{
public:

    [[nodiscard]]
    double minimum() const noexcept;

    [[nodiscard]]
    double maximum() const noexcept;

    [[nodiscard]]
    double range() const noexcept;

private:

    explicit CourseAnalysis(
        double minimum,
        double maximum,
        double range);

    double m_minimum;
    double m_maximum;
    double m_range;

    friend CourseAnalysis courseAnalysis(
        const CourseSeries& series);
};

[[nodiscard]]
CourseAnalysis courseAnalysis(
    const CourseSeries& series);

} // namespace GeoCore::Movement