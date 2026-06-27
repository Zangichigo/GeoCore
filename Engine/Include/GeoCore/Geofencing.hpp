#pragma once

#include <GeoCore/ZoneMembership.hpp>
#include <GeoCore/ZoneTransition.hpp>

namespace GeoCore
{

ZoneTransition detectTransition(
    ZoneMembership previous,
    ZoneMembership current);

}