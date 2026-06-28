#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Math/Speed.hpp>
#include <GeoCore/PositionSample.hpp>

#include <chrono>

using namespace GeoCore;

TEST_CASE("Speed is zero when timestamps are identical")
{
    auto now = std::chrono::system_clock::now();

    PositionSample a(
        Position(48.8566, 2.3522),
        now);

    PositionSample b(
        Position(48.8576, 2.3532),
        now);

    REQUIRE(Math::speed(a, b) == 0.0);
}

TEST_CASE("Speed is positive when moving")
{
    auto now = std::chrono::system_clock::now();

    PositionSample a(
        Position(48.8566, 2.3522),
        now);

    PositionSample b(
        Position(48.8576, 2.3532),
        now + std::chrono::seconds(10));

    REQUIRE(Math::speed(a, b) > 0.0);
}

TEST_CASE("Speed is zero when position does not change")
{
    auto now = std::chrono::system_clock::now();

    PositionSample a(
        Position(48.8566, 2.3522),
        now);

    PositionSample b(
        Position(48.8566, 2.3522),
        now + std::chrono::seconds(10));

    REQUIRE(Math::speed(a, b) == 0.0);
}