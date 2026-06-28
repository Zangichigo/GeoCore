#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Math/Distance.hpp>
#include <GeoCore/Position.hpp>

using namespace GeoCore;

TEST_CASE("Distance between identical positions is zero")
{
    Position p(48.8566, 2.3522);

    REQUIRE(Math::distance(p, p) == 0.0);
}

TEST_CASE("Distance between Paris and Lyon is positive")
{
    Position paris(48.8566, 2.3522);
    Position lyon(45.7640, 4.8357);

    REQUIRE(Math::distance(paris, lyon) > 0.0);
}