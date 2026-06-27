#pragma once

namespace GeoCore
{
    class Position
    {
    public:
        Position(double latitude, double longitude);

        double latitude() const noexcept;
        double longitude() const noexcept;

    private:
        double latitude_;
        double longitude_;
    };
}