#include <GeoCore/Math/Speed.hpp>

#include <GeoCore/Math/Distance.hpp>

#include <chrono>

namespace GeoCore::Math
{

double speed(
    const PositionSample& from,
    const PositionSample& to)
{
    const double distanceMeters =
        distance(
            from.position(),
            to.position());

    const auto duration =
        to.timestamp() - from.timestamp();

    const double seconds =
        std::chrono::duration<double>(duration).count();

    if (seconds <= 0.0)
    {
        return 0.0;
    }

    return distanceMeters / seconds;
}

} // namespace GeoCore::Math