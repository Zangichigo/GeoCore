#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Movement/course.hpp>

#include <GeoCore/Position.hpp>
#include <GeoCore/PositionSample.hpp>

#include <chrono>

using namespace GeoCore;

TEST_CASE("course north")
{
    auto t0 = std::chrono::system_clock::now();

    PositionSample a(
        Position(48.8566, 2.3522),
        t0);

    PositionSample b(
        Position(48.8666, 2.3522),
        t0 + std::chrono::seconds(10));

    double course =
        Movement::course(a, b);

    REQUIRE(course < 5.0);
}

TEST_CASE("course east")
{
    auto t0 = std::chrono::system_clock::now();

    PositionSample a(
        Position(48.8566, 2.3522),
        t0);

    PositionSample b(
        Position(48.8566, 2.3622),
        t0 + std::chrono::seconds(10));

    double course =
        Movement::course(a, b);

    REQUIRE(course > 85.0);
    REQUIRE(course < 95.0);
}

TEST_CASE("course south")
{
    auto t0 = std::chrono::system_clock::now();

    PositionSample a(
        Position(48.8566, 2.3522),
        t0);

    PositionSample b(
        Position(48.8466, 2.3522),
        t0 + std::chrono::seconds(10));

    double course =
        Movement::course(a, b);

    REQUIRE(course > 175.0);
    REQUIRE(course < 185.0);
}

TEST_CASE("course west")
{
    auto t0 = std::chrono::system_clock::now();

    PositionSample a(
        Position(48.8566, 2.3522),
        t0);

    PositionSample b(
        Position(48.8566, 2.3422),
        t0 + std::chrono::seconds(10));

    double course =
        Movement::course(a, b);

    REQUIRE(course > 265.0);
    REQUIRE(course < 275.0);
}