#pragma once

namespace GeoCore
{
    class Decision
    {
    public:
        explicit Decision(bool inside);

        bool inside() const noexcept;

    private:
        bool inside_;
    };
}