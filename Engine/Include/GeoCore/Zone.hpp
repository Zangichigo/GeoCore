#pragma once

#include <memory>
#include <string>

#include <GeoCore/IGeometry.hpp>

namespace GeoCore
{
    class Zone
    {
    public:
        Zone(std::string name, std::unique_ptr<IGeometry> geometry);

        const std::string& name() const noexcept;

        bool contains(const Position& position) const;

    private:
        std::string name_;
        std::unique_ptr<IGeometry> geometry_;
    };
}