#pragma once

#include <GeoCore/IGeometry.hpp>
#include <GeoCore/Position.hpp>

namespace GeoCore
{
    class Circle : public IGeometry
    {
    public:
        Circle(Position center, double radius);

        bool contains(const Position& position) const override;

    private:
        Position center_;
        double radius_;
    };
}