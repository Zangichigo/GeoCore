#include <GeoCore/Engine.hpp>
#include <GeoCore/Zone.hpp>
#include <GeoCore/Circle.hpp>

#include <iostream>
#include <memory>

#include <GeoCore/Polygon.hpp>
#include <vector>

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

    Polygon garden(
{
    Position(0.0, 0.0),
    Position(0.0, 10.0),
    Position(10.0, 10.0),
    Position(10.0, 0.0)
});

std::cout << '\n';

std::cout << "Polygon test\n";

std::cout << "Inside (5,5): "
          << garden.contains(Position(5.0, 5.0))
          << '\n';

std::cout << "Outside (15,5): "
          << garden.contains(Position(15.0, 5.0))
          << '\n';

    return 0;
}