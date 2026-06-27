#pragma once
#include <GeoCore/ZoneMembership.hpp>

namespace GeoCore
{
    class ProcessingResult
    {
    public:
      explicit ProcessingResult(ZoneMembership membership);

        bool inside() const noexcept;

    private:
        ZoneMembership membership_;
        
    };
}