#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Math/NormalizeAngle.hpp>

using namespace GeoCore;

TEST_CASE("Normalize zero angle")
{
    REQUIRE(Math::normalizeAngle(0.0) == 0.0);
}

TEST_CASE("Normalize positive angle")
{
    REQUIRE(Math::normalizeAngle(45.0) == 45.0);
}

TEST_CASE("Normalize 360 degrees")
{
    REQUIRE(Math::normalizeAngle(360.0) == 0.0);
}

TEST_CASE("Normalize angle greater than 360")
{
    REQUIRE(Math::normalizeAngle(361.0) == 1.0);
}

TEST_CASE("Normalize negative angle")
{
    REQUIRE(Math::normalizeAngle(-1.0) == 359.0);
}

TEST_CASE("Normalize negative quarter turn")
{
    REQUIRE(Math::normalizeAngle(-90.0) == 270.0);
}

TEST_CASE("Normalize multiple positive turns")
{
    REQUIRE(Math::normalizeAngle(720.0) == 0.0);
}

TEST_CASE("Normalize multiple negative turns")
{
    REQUIRE(Math::normalizeAngle(-721.0) == 359.0);
}