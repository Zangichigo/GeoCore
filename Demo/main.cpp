#include <GeoCore/Engine.hpp>
#include <GeoCore/Zone.hpp>
#include <GeoCore/Circle.hpp>

#include <iostream>
#include <memory>

int main()
{
    using namespace GeoCore;

    Engine engine;

    engine.addZone(
        Zone(
            "Home",
            std::make_unique<Circle>(
                Position(48.8566, 2.3522),
                100.0)));

    WorldState state(
        Position(48.8567, 2.3523));

    ProcessingResult result = engine.process(state);

    std::cout << std::boolalpha
              << "Inside: "
              << result.inside()
              << '\n';

    return 0;
}