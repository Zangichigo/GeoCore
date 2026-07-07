#pragma once

#include <span>

namespace GeoCore::Math
{

/**
 * @brief Computes the circular mean of a set of angles.
 *
 * The input angles are expressed in degrees.
 *
 * The returned value is normalized to the interval [0°, 360°).
 *
 * Empty input returns 0°.
 *
 * @param angles Angular values in degrees.
 *
 * @return Circular mean in degrees.
 */
[[nodiscard]]
double circularMean(
    std::span<const double> angles);

} // namespace GeoCore::Math