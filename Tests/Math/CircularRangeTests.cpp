#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <GeoCore/Math/CircularRange.hpp>

#include <array>
#include <vector>

using namespace GeoCore;

TEST_CASE("CircularRange of empty input")
{
    std::vector<double> angles;

    REQUIRE_THAT(
        Math::circularRange(angles),
        Catch::Matchers::WithinAbs(0.0, 1e-6));
}

TEST_CASE("CircularRange of single angle")
{
    std::array<double, 1> angles
    {
        42.0
    };

    REQUIRE_THAT(
        Math::circularRange(angles),
        Catch::Matchers::WithinAbs(0.0, 1e-6));
}

TEST_CASE("CircularRange of simple sequence")
{
    std::array<double, 3> angles
    {
        10.0,
        20.0,
        30.0
    };

    REQUIRE_THAT(
        Math::circularRange(angles),
        Catch::Matchers::WithinAbs(20.0, 1e-6));
}

TEST_CASE("CircularRange handles wraparound")
{
    std::array<double, 2> angles
    {
        359.0,
        1.0
    };

    REQUIRE_THAT(
        Math::circularRange(angles),
        Catch::Matchers::WithinAbs(2.0, 1e-3));
}

TEST_CASE("CircularRange handles another wraparound")
{
    std::array<double, 2> angles
    {
        350.0,
        10.0
    };

    REQUIRE_THAT(
        Math::circularRange(angles),
        Catch::Matchers::WithinAbs(20.0, 1e-3));
}

TEST_CASE("CircularRange of opposite directions")
{
    std::array<double, 2> angles
    {
        0.0,
        180.0
    };

    REQUIRE_THAT(
        Math::circularRange(angles),
        Catch::Matchers::WithinAbs(180.0, 1e-6));
}

TEST_CASE("CircularRange normalizes input")
{
    std::array<double, 3> angles
    {
        -10.0,
        350.0,
        370.0
    };

    REQUIRE_THAT(
        Math::circularRange(angles),
        Catch::Matchers::WithinAbs(20.0, 1e-3));
}

TEST_CASE("CircularRange is invariant under normalization")
{
    std::array<double, 3> a
    {
        -10.0,
        350.0,
        370.0
    };

    std::array<double, 3> b
    {
        350.0,
        350.0,
        10.0
    };

    REQUIRE_THAT(
        Math::circularRange(a),
        Catch::Matchers::WithinAbs(
            Math::circularRange(b),
            1e-6));
}