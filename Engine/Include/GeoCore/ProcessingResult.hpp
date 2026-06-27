#pragma once

namespace GeoCore
{
    class ProcessingResult
    {
    public:
        explicit ProcessingResult(bool inside);

        bool inside() const noexcept;

    private:
        bool inside_;
    };
}