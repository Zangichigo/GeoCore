#include <GeoCore/Circle.hpp>
#include <GeoCore/Engine.hpp>
#include <GeoCore/Geofencing.hpp>
#include <GeoCore/Math/Bearing.hpp>
#include <GeoCore/Polygon.hpp>
#include <GeoCore/Zone.hpp>

#include <iostream>
#include <memory>
#include <vector>

#include <GeoCore/PositionSample.hpp>
#include <chrono>

#include <GeoCore/PositionHistory.hpp>
#include <GeoCore/Math/Speed.hpp>

#include <GeoCore/Units.hpp>

int main()
{
    using namespace GeoCore;

    //
    // Circle / Engine demonstration
    //
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

    std::cout << std::boolalpha;
    std::cout << "Circle test\n";
    std::cout << "Inside: "
              << result.inside()
              << '\n';

    //
    // Polygon demonstration
    //
    Polygon garden(
        std::vector<Position>
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

    //
    // Zone transition demonstration
    //
    std::cout << '\n';
    std::cout << "Transition test\n";

    std::cout << "Outside -> Inside : "
              << static_cast<int>(
                     detectTransition(
                         ZoneMembership::Outside,
                         ZoneMembership::Inside))
              << '\n';

    //
    // Bearing demonstration
    //
    Position paris(48.8566, 2.3522);
    Position london(51.5074, -0.1278);
    Position lyon(45.7640, 4.8357);

    std::cout << '\n';
    std::cout << "Bearing test\n";

    std::cout << "Paris -> London : "
              << Math::bearing(paris, london)
              << "°\n";

    std::cout << "Paris -> Lyon   : "
              << Math::bearing(paris, lyon)
              << "°\n";
//
// PositionSample demonstration
//
    std::cout << '\n';
std::cout << "PositionSample test\n";

PositionSample sample(
    Position(48.8566, 2.3522),
    std::chrono::system_clock::now());

std::cout << "Latitude  : "
          << sample.position().latitude()
          << '\n';

std::cout << "Longitude : "
          << sample.position().longitude()
          << '\n';


//
// PositionHistory demonstration
//
std::cout << '\n';
std::cout << "PositionHistory test\n";

PositionHistory history;

history.push_back(
    PositionSample(
        Position(48.8566, 2.3522),
        std::chrono::system_clock::now()));

history.push_back(
    PositionSample(
        Position(45.7640, 4.8357),
        std::chrono::system_clock::now()));

std::cout << "Size      : "
          << history.size()
          << '\n';

std::cout << "First lat : "
          << history.front().position().latitude()
          << '\n';

std::cout << "Last lat  : "
          << history.back().position().latitude()
          << '\n';


PositionSample sample1(
    Position(48.8566, 2.3522),
    std::chrono::system_clock::now());

PositionSample sample2(
    Position(48.8576, 2.3532),
    sample1.timestamp() + std::chrono::seconds(10));

double speedMs =
    Math::speed(sample1, sample2);

std::cout << "Speed : "
          << speedMs
          << " m/s ("
          << Units::toKmh(speedMs)
          << " km/h, "
          << Units::toMph(speedMs)
          << " mph)\n";

    return 0;
}