#include <GeoCore/ProcessingResult.hpp>

namespace GeoCore
{

ProcessingResult::ProcessingResult(bool inside)
    : inside_(inside)
{
}

bool ProcessingResult::inside() const noexcept
{
    return inside_;
}

}