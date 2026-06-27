#include <GeoCore/Math/Distance.hpp>

#include <cmath>

namespace
{
    constexpr double EarthRadius = 6371000.0; // meters

    constexpr double Pi = 3.14159265358979323846;

    double toRadians(double degrees)
    {
        return degrees * Pi / 180.0;
    }
}

namespace GeoCore::Math
{

double distance(const Position& a, const Position& b)
{
    const double latitude1 = toRadians(a.latitude());
    const double longitude1 = toRadians(a.longitude());

    const double latitude2 = toRadians(b.latitude());
    const double longitude2 = toRadians(b.longitude());

    const double deltaLatitude = latitude2 - latitude1;
    const double deltaLongitude = longitude2 - longitude1;

    const double haversine =
        std::sin(deltaLatitude / 2.0) * std::sin(deltaLatitude / 2.0) +
        std::cos(latitude1) * std::cos(latitude2) *
        std::sin(deltaLongitude / 2.0) * std::sin(deltaLongitude / 2.0);

    const double centralAngle =
        2.0 * std::atan2(std::sqrt(haversine),
                         std::sqrt(1.0 - haversine));

    return EarthRadius * centralAngle;
}

}