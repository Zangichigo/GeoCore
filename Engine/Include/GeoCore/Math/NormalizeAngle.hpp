#pragma once

namespace GeoCore::Math
{

/**
 * @brief Normalizes an angle to the interval [0°, 360°).
 *
 * Any input angle is converted to its canonical representation
 * within the range [0°, 360°).
 *
 * Examples:
 *
 * normalizeAngle(0)      -> 0
 * normalizeAngle(45)     -> 45
 * normalizeAngle(360)    -> 0
 * normalizeAngle(361)    -> 1
 * normalizeAngle(-1)     -> 359
 * normalizeAngle(-90)    -> 270
 * normalizeAngle(720)    -> 0
 *
 * @param angle Angle in degrees.
 *
 * @return Normalized angle in the interval [0°, 360°).
 */
[[nodiscard]]
double normalizeAngle(double angle);

} // namespace GeoCore::Math