#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <GeoCore/Math/CircularMean.hpp>

#include <array>
#include <vector>

using namespace GeoCore;

TEST_CASE("CircularMean of empty input is zero")
{
    std::vector<double> angles;

    REQUIRE_THAT(
        Math::circularMean(angles),
        Catch::Matchers::WithinAbs(0.0, 1e-6));
}

TEST_CASE("CircularMean of a single angle")
{
    std::array<double, 1> angles
    {
        42.0
    };

    REQUIRE_THAT(
        Math::circularMean(angles),
        Catch::Matchers::WithinAbs(42.0, 1e-6));
}

TEST_CASE("CircularMean of identical angles")
{
    std::array<double, 3> angles
    {
        90.0,
        90.0,
        90.0
    };

    REQUIRE_THAT(
        Math::circularMean(angles),
        Catch::Matchers::WithinAbs(90.0, 1e-6));
}

TEST_CASE("CircularMean handles wraparound")
{
    std::array<double, 2> angles
    {
        359.0,
        1.0
    };

    REQUIRE_THAT(
        Math::circularMean(angles),
        Catch::Matchers::WithinAbs(0.0, 1e-3));
}

TEST_CASE("CircularMean of opposite angles")
{
    std::array<double, 2> angles
    {
        90.0,
        270.0
    };

    const double mean =
        Math::circularMean(angles);

    REQUIRE(
        mean >= 0.0);

    REQUIRE(
        mean < 360.0);
}

TEST_CASE("CircularMean of simple sequence")
{
    std::array<double, 3> angles
    {
        10.0,
        20.0,
        30.0
    };

    REQUIRE_THAT(
        Math::circularMean(angles),
        Catch::Matchers::WithinAbs(20.0, 1e-6));
}

TEST_CASE("CircularMean normalizes input angles")
{
    std::array<double, 3> angles
    {
        -10.0,
        350.0,
        710.0
    };

    REQUIRE_THAT(
        Math::circularMean(angles),
        Catch::Matchers::WithinAbs(350.0, 1e-3));
}