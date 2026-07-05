#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Position.hpp>
#include <GeoCore/PositionSample.hpp>
#include <GeoCore/Track.hpp>

#include <GeoCore/Tracking/AverageSpeed.hpp>

#include <chrono>

using namespace GeoCore;

TEST_CASE("Average speed is zero when track is empty")
{
    Track track;

    REQUIRE(
        Tracking::averageSpeed(track) == 0.0);
}

TEST_CASE("Average speed is zero with one sample")
{
    Track track;

    track.push_back(
        PositionSample(
            Position(48.8566, 2.3522),
            std::chrono::system_clock::now()));

    REQUIRE(
        Tracking::averageSpeed(track) == 0.0);
}

TEST_CASE("Average speed is zero when duration is zero")
{
    Track track;

    auto timestamp = std::chrono::system_clock::now();

    track.push_back(
        PositionSample(
            Position(48.8566, 2.3522),
            timestamp));

    track.push_back(
        PositionSample(
            Position(48.8576, 2.3532),
            timestamp));

    REQUIRE(
        Tracking::averageSpeed(track) == 0.0);
}

TEST_CASE("Average speed is positive when moving")
{
    Track track;

    auto timestamp = std::chrono::system_clock::now();

    track.push_back(
        PositionSample(
            Position(48.8566, 2.3522),
            timestamp));

    track.push_back(
        PositionSample(
            Position(48.8576, 2.3532),
            timestamp + std::chrono::seconds(10)));

    REQUIRE(
        Tracking::averageSpeed(track) > 0.0);
}