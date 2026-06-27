#include <GeoCore/ProcessingResult.hpp>

namespace GeoCore
{

ProcessingResult::ProcessingResult(
    ZoneMembership membership)
    : membership_(membership)
{
}

bool ProcessingResult::inside() const noexcept
{
    return membership_ == ZoneMembership::Inside;
}

}