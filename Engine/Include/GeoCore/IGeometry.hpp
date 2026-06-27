#pragma once

#include <GeoCore/Position.hpp>

namespace GeoCore
{
    class IGeometry
    {
    public:
        virtual ~IGeometry() = default;

        virtual bool contains(const Position& position) const = 0;
    };
}