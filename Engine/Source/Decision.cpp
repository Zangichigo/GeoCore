#include <GeoCore/Decision.hpp>

namespace GeoCore
{

Decision::Decision(bool inside)
    : inside_(inside)
{
}

bool Decision::inside() const noexcept
{
    return inside_;
}

}