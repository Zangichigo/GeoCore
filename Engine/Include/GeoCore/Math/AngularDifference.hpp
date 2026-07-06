#pragma once

namespace GeoCore::Math
{

/**
 * @brief Computes the signed shortest angular distance between two angles.
 *
 * The returned value is normalized to the interval (-180°, +180°].
 *
 * This function performs a purely mathematical comparison between two
 * angular values.
 *
 * It does not infer any physical meaning from those values.
 *
 * Examples:
 *
 * angularDifference(10, 20)   ->  10
 * angularDifference(20, 10)   -> -10
 * angularDifference(350, 10)  ->  20
 * angularDifference(10, 350)  -> -20
 *
 * @param angle1 First angular value in degrees.
 * @param angle2 Second angular value in degrees.
 *
 * @return Signed shortest angular distance in degrees.
 */
[[nodiscard]]
double angularDifference(
    double angle1,
    double angle2);

} // namespace GeoCore::Math