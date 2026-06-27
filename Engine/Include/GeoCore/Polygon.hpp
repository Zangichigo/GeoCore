#pragma once

#include <GeoCore/IGeometry.hpp>
#include <GeoCore/Position.hpp>

#include <vector>

namespace GeoCore
{
    class Polygon : public IGeometry
    {
    public:
        explicit Polygon(std::vector<Position> vertices);

        bool contains(const Position& position) const override;

    private:
        std::vector<Position> vertices_;
    };
}