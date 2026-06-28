#include <GeoCore/Units.hpp>
#include <GeoCore/Constants.hpp>

namespace GeoCore::Units
{

double toKmh(double metersPerSecond) noexcept
{
    return metersPerSecond *
       Constants::SecondsPerHour /
       Constants::MetersPerKilometer;
}

double toMph(double metersPerSecond) noexcept
{
    return metersPerSecond *
       Constants::SecondsPerHour /
       Constants::MetersPerMile;
}

double toKnots(double metersPerSecond) noexcept
{
    return metersPerSecond *
       Constants::SecondsPerHour /
       Constants::MetersPerNauticalMile;
}

double fromKmh(double kilometersPerHour) noexcept
{
    return kilometersPerHour *
       Constants::MetersPerKilometer /
       Constants::SecondsPerHour;
}

double fromMph(double milesPerHour) noexcept
{
    return milesPerHour *
       Constants::MetersPerMile /
       Constants::SecondsPerHour;
}

double fromKnots(double knots) noexcept
{
    return knots *
       Constants::MetersPerNauticalMile /
       Constants::SecondsPerHour;
}

} // namespace GeoCore::Units