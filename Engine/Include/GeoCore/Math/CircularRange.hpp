#pragma once

#include <span>

namespace GeoCore::Math
{

/**
 * @brief Computes the minimal angular range covering a set of angles.
 *
 * The input angles are expressed in degrees.
 *
 * The returned value is always in the interval [0°, 180°].
 *
 * Empty input returns 0°.
 *
 * @param angles Angular values in degrees.
 *
 * @return Minimal circular range in degrees.
 */
[[nodiscard]]
double circularRange(
    std::span<const double> angles);

} // namespace GeoCore::Math