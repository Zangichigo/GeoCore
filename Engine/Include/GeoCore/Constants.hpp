#pragma once

namespace GeoCore::Constants
{

// Distance
constexpr double MetersPerKilometer = 1000.0;
constexpr double MetersPerMile = 1609.344;
constexpr double MetersPerNauticalMile = 1852.0;

// Time
constexpr double SecondsPerMinute = 60.0;
constexpr double MinutesPerHour = 60.0;
constexpr double SecondsPerHour =
    SecondsPerMinute * MinutesPerHour;

} // namespace GeoCore::Constants