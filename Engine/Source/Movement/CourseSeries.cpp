#include <GeoCore/Movement/CourseSeries.hpp>

#include <GeoCore/Movement/Course.hpp>

#include <GeoCore/Track.hpp>

#include <utility>

namespace GeoCore::Movement
{

CourseSeries::CourseSeries(
    std::vector<double> courses)
    : m_courses(std::move(courses))
{
}

bool CourseSeries::empty() const noexcept
{
    return m_courses.empty();
}

std::size_t CourseSeries::size() const noexcept
{
    return m_courses.size();
}

double CourseSeries::operator[](std::size_t index) const
{
    return m_courses[index];
}

const std::vector<double>& CourseSeries::values() const noexcept
{
    return m_courses;
}

CourseSeries courseSeries(const Track& track)
{
    std::vector<double> courses;

    if (track.size() < 2)
    {
        return CourseSeries(std::move(courses));
    }

    for (std::size_t i = 1; i < track.size(); ++i)
    {
        courses.push_back(
            course(
                track[i - 1],
                track[i]));
    }

    return CourseSeries(std::move(courses));
}
}

 // namespace GeoCore::Movement