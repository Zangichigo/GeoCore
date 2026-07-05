#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Movement/Acceleration.hpp>

#include <GeoCore/Position.hpp>
#include <GeoCore/PositionSample.hpp>

#include <chrono>
#include <cmath>

using namespace GeoCore;

TEST_CASE("Acceleration is zero with identical timestamps")
{
    auto timestamp = std::chrono::system_clock::now();

    PositionSample a(
        Position(48.8566, 2.3522),
        timestamp);

    PositionSample b(
        Position(48.8567, 2.3523),
        timestamp);

    PositionSample c(
        Position(48.8568, 2.3524),
        timestamp);

    REQUIRE(
        Movement::acceleration(a, b, c) == 0.0);
}

TEST_CASE("Acceleration is approximately zero at constant speed")
{
    auto t0 = std::chrono::system_clock::now();

    PositionSample a(
        Position(48.856600, 2.352200),
        t0);

    PositionSample b(
        Position(48.856700, 2.352300),
        t0 + std::chrono::seconds(10));

    PositionSample c(
        Position(48.856800, 2.352400),
        t0 + std::chrono::seconds(20));

    REQUIRE(
        std::abs(
            Movement::acceleration(a, b, c))
        < 0.01);
}

TEST_CASE("Acceleration is positive when speed increases")
{
    auto t0 = std::chrono::system_clock::now();

    PositionSample a(
        Position(48.856600, 2.352200),
        t0);

    PositionSample b(
        Position(48.856650, 2.352250),
        t0 + std::chrono::seconds(10));

    PositionSample c(
        Position(48.857000, 2.352600),
        t0 + std::chrono::seconds(20));

    REQUIRE(
        Movement::acceleration(a, b, c) > 0.0);
}

TEST_CASE("Acceleration is negative when speed decreases")
{
    auto t0 = std::chrono::system_clock::now();

    PositionSample a(
        Position(48.856600, 2.352200),
        t0);

    PositionSample b(
        Position(48.857000, 2.352600),
        t0 + std::chrono::seconds(10));

    PositionSample c(
        Position(48.857050, 2.352650),
        t0 + std::chrono::seconds(20));

    REQUIRE(
        Movement::acceleration(a, b, c) < 0.0);
}