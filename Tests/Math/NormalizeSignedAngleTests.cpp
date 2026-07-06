#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Math/NormalizeSignedAngle.hpp>

using namespace GeoCore;

TEST_CASE("Normalize signed zero")
{
    REQUIRE(Math::normalizeSignedAngle(0.0) == 0.0);
}

TEST_CASE("Normalize signed positive")
{
    REQUIRE(Math::normalizeSignedAngle(45.0) == 45.0);
}

TEST_CASE("Normalize signed 180")
{
    REQUIRE(Math::normalizeSignedAngle(180.0) == 180.0);
}

TEST_CASE("Normalize signed 181")
{
    REQUIRE(Math::normalizeSignedAngle(181.0) == -179.0);
}

TEST_CASE("Normalize signed 270")
{
    REQUIRE(Math::normalizeSignedAngle(270.0) == -90.0);
}

TEST_CASE("Normalize signed 360")
{
    REQUIRE(Math::normalizeSignedAngle(360.0) == 0.0);
}

TEST_CASE("Normalize signed -181")
{
    REQUIRE(Math::normalizeSignedAngle(-181.0) == 179.0);
}

TEST_CASE("Normalize signed -270")
{
    REQUIRE(Math::normalizeSignedAngle(-270.0) == 90.0);
}

TEST_CASE("Normalize signed -180")
{
    REQUIRE(Math::normalizeSignedAngle(-180.0) == 180.0);
}

TEST_CASE("Normalize signed 540")
{
    REQUIRE(Math::normalizeSignedAngle(540.0) == 180.0);
}