#include <GeoCore/Movement/Acceleration.hpp>

#include <GeoCore/Math/Speed.hpp>

#include <chrono>

namespace GeoCore::Movement
{

double acceleration(
    const PositionSample& previous,
    const PositionSample& current,
    const PositionSample& next)
{
    const double speed1 =
        Math::speed(previous, current);

    const double speed2 =
        Math::speed(current, next);

    const auto interval1 =
        current.timestamp() - previous.timestamp();

    const auto interval2 =
        next.timestamp() - current.timestamp();

    const double deltaTime =
        (std::chrono::duration<double>(interval1).count() +
         std::chrono::duration<double>(interval2).count()) / 2.0;

    if (deltaTime <= 0.0)
    {
        return 0.0;
    }

    return (speed2 - speed1) / deltaTime;
}

} // namespace GeoCore::Movement