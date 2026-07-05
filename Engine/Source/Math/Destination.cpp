#include <GeoCore/Math/Destination.hpp>
#include <GeoCore/Math/MathUtils.hpp>

#include <cmath>

namespace GeoCore::Math
{

Position destination(
    const Position& start,
    double bearingDegrees,
    double distanceMeters)
{
    const double latitude =
        toRadians(start.latitude());

    const double longitude =
        toRadians(start.longitude());

    const double bearing =
        toRadians(bearingDegrees);

    const double angularDistance =
        distanceMeters / EarthRadius;

    const double destinationLatitude =
        std::asin(
            std::sin(latitude) * std::cos(angularDistance) +
            std::cos(latitude) * std::sin(angularDistance) * std::cos(bearing));

    const double destinationLongitude =
        longitude +
        std::atan2(
            std::sin(bearing) * std::sin(angularDistance) * std::cos(latitude),
            std::cos(angularDistance) -
            std::sin(latitude) * std::sin(destinationLatitude));

    return Position(
        toDegrees(destinationLatitude),
        toDegrees(destinationLongitude));
}

} // namespace GeoCore::Math