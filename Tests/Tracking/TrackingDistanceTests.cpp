#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Tracking/Distance.hpp>

#include <chrono>

using namespace GeoCore;

static PositionSample sample(double latitude, double longitude)
{
    return PositionSample(
        Position(latitude, longitude),
        std::chrono::system_clock::now());
}

TEST_CASE("Track distance is zero when empty")
{
    Track track;

    REQUIRE(Tracking::distance(track) == 0.0);
}

TEST_CASE("Track distance is zero with one sample")
{
    Track track;

    track.add(sample(48.8566, 2.3522));

    REQUIRE(Tracking::distance(track) == 0.0);
}

TEST_CASE("Track distance is positive with two samples")
{
    Track track;

    track.add(sample(48.8566, 2.3522));
    track.add(sample(45.7640, 4.8357));

    REQUIRE(Tracking::distance(track) > 0.0);
}

TEST_CASE("Track distance increases with additional samples")
{
    Track track;

    track.add(sample(48.8566, 2.3522));
    track.add(sample(45.7640, 4.8357));

    const double firstDistance =
        Tracking::distance(track);

    track.add(sample(43.2965, 5.3698));

    const double secondDistance =
        Tracking::distance(track);

    REQUIRE(secondDistance > firstDistance);
}