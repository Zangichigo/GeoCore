#include <GeoCore/Zone.hpp>

namespace GeoCore
{

Zone::Zone(std::string name, std::unique_ptr<IGeometry> geometry)
    : name_(std::move(name)),
      geometry_(std::move(geometry))
{
}

const std::string& Zone::name() const noexcept
{
    return name_;
}

bool Zone::contains(const Position& position) const
{
    return geometry_->contains(position);
}

}