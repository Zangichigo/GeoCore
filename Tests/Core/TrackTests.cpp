#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Track.hpp>

#include <chrono>

using namespace GeoCore;

static PositionSample sample(double latitude, double longitude)
{
    return PositionSample(
        Position(latitude, longitude),
        std::chrono::system_clock::now());
}

TEST_CASE("Track is empty when created")
{
    Track track;

    REQUIRE(track.empty());
    REQUIRE(track.size() == 0);
}

TEST_CASE("Track contains one sample after add")
{
    Track track;

    track.add(sample(48.8566, 2.3522));

    REQUIRE_FALSE(track.empty());
    REQUIRE(track.size() == 1);
}

TEST_CASE("Track first and last are identical with one sample")
{
    Track track;

    track.add(sample(48.8566, 2.3522));

    REQUIRE(track.first().position().latitude() == 48.8566);
    REQUIRE(track.last().position().latitude() == 48.8566);
}

TEST_CASE("Track stores samples in insertion order")
{
    Track track;

    track.add(sample(48.8566, 2.3522));
    track.add(sample(45.7640, 4.8357));

    REQUIRE(track.size() == 2);

    REQUIRE(track.first().position().latitude() == 48.8566);
    REQUIRE(track.last().position().latitude() == 45.7640);
}

TEST_CASE("Track operator[] returns correct sample")
{
    Track track;

    track.add(sample(48.8566, 2.3522));
    track.add(sample(45.7640, 4.8357));

    REQUIRE(track[0].position().latitude() == 48.8566);
    REQUIRE(track[1].position().latitude() == 45.7640);
}

TEST_CASE("Track exposes underlying samples")
{
    Track track;

    track.add(sample(48.8566, 2.3522));
    track.add(sample(45.7640, 4.8357));

    REQUIRE(track.samples().size() == 2);
}
