#include <GeoCore/Geofencing.hpp>

namespace GeoCore
{

ZoneTransition detectTransition(
    ZoneMembership previous,
    ZoneMembership current)
{
    if (previous == ZoneMembership::Outside &&
        current == ZoneMembership::Inside)
    {
        return ZoneTransition::Enter;
    }

    if (previous == ZoneMembership::Inside &&
        current == ZoneMembership::Outside)
    {
        return ZoneTransition::Exit;
    }

    return ZoneTransition::None;
}

}