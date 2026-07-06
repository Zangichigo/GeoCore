#pragma once

namespace GeoCore::Math
{

/**
 * @brief Normalizes an angle to the interval (-180°, +180°].
 *
 * Any input angle is converted to its canonical signed representation.
 *
 * Examples:
 *
 * normalizeSignedAngle(0)      ->   0
 * normalizeSignedAngle(10)     ->  10
 * normalizeSignedAngle(180)    -> 180
 * normalizeSignedAngle(181)    -> -179
 * normalizeSignedAngle(270)    -> -90
 * normalizeSignedAngle(360)    ->   0
 * normalizeSignedAngle(-181)   -> 179
 * normalizeSignedAngle(-270)   ->  90
 *
 * @param angle Angle in degrees.
 *
 * @return Normalized signed angle in (-180°, +180°].
 */
[[nodiscard]]
double normalizeSignedAngle(double angle);

} // namespace GeoCore::Math