#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Position.hpp>
#include <GeoCore/PositionSample.hpp>
#include <GeoCore/Track.hpp>
#include <GeoCore/Tracking/Duration.hpp>

#include <chrono>

using namespace GeoCore;

TEST_CASE("Track duration is zero when empty")
{
    Track track;

    REQUIRE(
        Tracking::duration(track) ==
        std::chrono::system_clock::duration::zero());
}

TEST_CASE("Track duration is zero with one sample")
{
    Track track;

    track.add(
        PositionSample(
            Position(48.8566, 2.3522),
            std::chrono::system_clock::now()));

    REQUIRE(
        Tracking::duration(track) ==
        std::chrono::system_clock::duration::zero());
}

TEST_CASE("Track duration with two samples")
{
    Track track;

    auto start = std::chrono::system_clock::now();

    track.add(
        PositionSample(
            Position(48.8566, 2.3522),
            start));

    track.add(
        PositionSample(
            Position(48.8567, 2.3523),
            start + std::chrono::seconds(10)));

    REQUIRE(
        Tracking::duration(track) ==
        std::chrono::seconds(10));
}

TEST_CASE("Track duration increases with additional samples")
{
    Track track;

    auto start = std::chrono::system_clock::now();

    track.add(
        PositionSample(
            Position(48.8566, 2.3522),
            start));

    track.add(
        PositionSample(
            Position(48.8567, 2.3523),
            start + std::chrono::seconds(5)));

    track.add(
        PositionSample(
            Position(48.8568, 2.3524),
            start + std::chrono::seconds(15)));

    REQUIRE(
        Tracking::duration(track) ==
        std::chrono::seconds(15));
}