#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Math/AngularDifference.hpp>

using namespace GeoCore;

TEST_CASE("Angular difference is zero for identical angles")
{
    REQUIRE(Math::angularDifference(45.0, 45.0) == 0.0);
}

TEST_CASE("Angular difference is positive")
{
    REQUIRE(Math::angularDifference(10.0, 20.0) == 10.0);
}

TEST_CASE("Angular difference is negative")
{
    REQUIRE(Math::angularDifference(20.0, 10.0) == -10.0);
}

TEST_CASE("Angular difference wraps across zero positively")
{
    REQUIRE(Math::angularDifference(350.0, 10.0) == 20.0);
}

TEST_CASE("Angular difference wraps across zero negatively")
{
    REQUIRE(Math::angularDifference(10.0, 350.0) == -20.0);
}

TEST_CASE("Angular difference handles 359 to 1 degrees")
{
    REQUIRE(Math::angularDifference(359.0, 1.0) == 2.0);
}

TEST_CASE("Angular difference handles 1 to 359 degrees")
{
    REQUIRE(Math::angularDifference(1.0, 359.0) == -2.0);
}

TEST_CASE("Angular difference normalizes values larger than 360 degrees")
{
    REQUIRE(Math::angularDifference(720.0, 810.0) == 90.0);
}

TEST_CASE("Angular difference normalizes negative angles")
{
    REQUIRE(Math::angularDifference(-10.0, 10.0) == 20.0);
}