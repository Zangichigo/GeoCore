#pragma once

namespace GeoCore::Units
{

double toKmh(double metersPerSecond) noexcept;

double toMph(double metersPerSecond) noexcept;

double toKnots(double metersPerSecond) noexcept;

double fromKmh(double kilometersPerHour) noexcept;

double fromMph(double milesPerHour) noexcept;

double fromKnots(double knots) noexcept;

} // namespace GeoCore::Units