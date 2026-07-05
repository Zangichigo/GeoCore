#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Movement/Stationary.hpp>

#include <GeoCore/Position.hpp>
#include <GeoCore/PositionSample.hpp>
#include <GeoCore/Track.hpp>

#include <chrono>

using namespace GeoCore;

TEST_CASE("Stationary is false when track is empty")
{
    Track track;

    REQUIRE_FALSE(
        Movement::stationary(
            track,
            5.0,
            std::chrono::seconds(10)));
}

TEST_CASE("Stationary is false with one sample")
{
    Track track;

    track.push_back(
        PositionSample(
            Position(48.8566, 2.3522),
            std::chrono::system_clock::now()));

    REQUIRE_FALSE(
        Movement::stationary(
            track,
            5.0,
            std::chrono::seconds(10)));
}

TEST_CASE("Stationary is false when duration is too short")
{
    Track track;

    auto start =
        std::chrono::system_clock::now();

    track.push_back(
        PositionSample(
            Position(48.8566, 2.3522),
            start));

    track.push_back(
        PositionSample(
            Position(48.8566, 2.3522),
            start + std::chrono::seconds(5)));

    REQUIRE_FALSE(
        Movement::stationary(
            track,
            5.0,
            std::chrono::seconds(10)));
}

TEST_CASE("Stationary is false when radius is exceeded")
{
    Track track;

    auto start =
        std::chrono::system_clock::now();

    track.push_back(
        PositionSample(
            Position(48.8566, 2.3522),
            start));

    track.push_back(
        PositionSample(
            Position(48.8666, 2.3622),
            start + std::chrono::seconds(60)));

    REQUIRE_FALSE(
        Movement::stationary(
            track,
            5.0,
            std::chrono::seconds(30)));
}

TEST_CASE("Stationary is true when duration and radius conditions are satisfied")
{
    Track track;

    auto start =
        std::chrono::system_clock::now();

    track.push_back(
        PositionSample(
            Position(48.856600, 2.352200),
            start));

    track.push_back(
        PositionSample(
            Position(48.856602, 2.352201),
            start + std::chrono::seconds(60)));

    REQUIRE(
        Movement::stationary(
            track,
            5.0,
            std::chrono::seconds(30)));
}