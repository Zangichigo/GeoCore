#pragma once

#include <GeoCore/Position.hpp>

namespace GeoCore
{
    class Rectangle
    {
    public:

        Rectangle(
            const Position& southWest,
            const Position& northEast);

        [[nodiscard]]
        bool contains(
            const Position& position) const;

        [[nodiscard]]
        const Position& southWest() const;

        [[nodiscard]]
        const Position& northEast() const;

    private:

        Position southWest_;
        Position northEast_;
    };
}