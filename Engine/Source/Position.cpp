#include <GeoCore/Position.hpp>

namespace GeoCore
{

Position::Position(double latitude, double longitude)
    : latitude_(latitude),
      longitude_(longitude)
{
}

double Position::latitude() const noexcept
{
    return latitude_;
}

double Position::longitude() const noexcept
{
    return longitude_;
}

}