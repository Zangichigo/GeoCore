#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Math/Bearing.hpp>
#include <GeoCore/Position.hpp>

using namespace GeoCore;

TEST_CASE("Bearing is always between 0 and 360 degrees")
{
    Position paris(48.8566, 2.3522);
    Position london(51.5074, -0.1278);

    const double bearing =
        Math::bearing(paris, london);

    REQUIRE(bearing >= 0.0);
    REQUIRE(bearing < 360.0);
}

TEST_CASE("Bearing from Paris to London is north-west")
{
    Position paris(48.8566, 2.3522);
    Position london(51.5074, -0.1278);

    const double bearing =
        Math::bearing(paris, london);

    REQUIRE(bearing > 300.0);
    REQUIRE(bearing < 340.0);
}

TEST_CASE("Bearing from Paris to Lyon is south-east")
{
    Position paris(48.8566, 2.3522);
    Position lyon(45.7640, 4.8357);

    const double bearing =
        Math::bearing(paris, lyon);

    REQUIRE(bearing > 120.0);
    REQUIRE(bearing < 180.0);
}