#pragma once

namespace GeoCore::Math
{

constexpr double Pi = 3.14159265358979323846;

constexpr double EarthRadius = 6371000.0; // meters

inline double toRadians(double degrees)
{
    return degrees * Pi / 180.0;
}

inline double toDegrees(double radians)
{
    return radians * 180.0 / Pi;
}

} // namespace GeoCore::Math