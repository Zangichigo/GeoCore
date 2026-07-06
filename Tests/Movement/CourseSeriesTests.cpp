#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Movement/CourseSeries.hpp>

#include <GeoCore/Track.hpp>

#include <catch2/catch_approx.hpp>

#include <catch2/matchers/catch_matchers_floating_point.hpp>

using namespace GeoCore;

TEST_CASE("CourseSeries is empty from an empty track")
{
    Track track;

    auto series =
        Movement::courseSeries(track);

    REQUIRE(series.empty());
    REQUIRE(series.size() == 0);
}

TEST_CASE("CourseSeries is empty with one sample")
{
    Track track;

    track.push_back(
        PositionSample(
            Position(48.8566, 2.3522),
            std::chrono::system_clock::now()));

    auto series =
        Movement::courseSeries(track);

    REQUIRE(series.empty());
    REQUIRE(series.size() == 0);
}

TEST_CASE("CourseSeries values container is empty")
{
    Track track;

    auto series =
        Movement::courseSeries(track);

    REQUIRE(series.values().empty());
}

TEST_CASE("CourseSeries contains one course from two samples")
{
    Track track;

    auto now = std::chrono::system_clock::now();

    track.push_back(
        PositionSample(
            Position(0.0, 0.0),
            now));

    track.push_back(
        PositionSample(
            Position(1.0, 0.0),
            now + std::chrono::seconds(1)));

    auto series =
        Movement::courseSeries(track);

    REQUIRE(series.size() == 1);
}

TEST_CASE("CourseSeries contains two courses from three samples")
{
    Track track;

    auto now = std::chrono::system_clock::now();

    track.push_back(
        PositionSample(
            Position(0.0, 0.0),
            now));

    track.push_back(
        PositionSample(
            Position(1.0, 0.0),
            now + std::chrono::seconds(1)));

    track.push_back(
        PositionSample(
            Position(2.0, 0.0),
            now + std::chrono::seconds(2)));

    auto series =
        Movement::courseSeries(track);

    REQUIRE(series.size() == 2);
}

TEST_CASE("CourseSeries computes north course")
{
    Track track;

    auto now = std::chrono::system_clock::now();

    track.push_back(
        PositionSample(
            Position(0.0, 0.0),
            now));

    track.push_back(
        PositionSample(
            Position(1.0, 0.0),
            now + std::chrono::seconds(1)));

    auto series =
        Movement::courseSeries(track);

    REQUIRE(series.size() == 1);
    REQUIRE_THAT(
    series[0],
    Catch::Matchers::WithinAbs(0.0, 0.1));
}

TEST_CASE("CourseSeries preserves course order")
{
    Track track;

    auto now = std::chrono::system_clock::now();

    track.push_back(
        PositionSample(
            Position(0.0, 0.0),
            now));

    track.push_back(
        PositionSample(
            Position(1.0, 0.0),
            now + std::chrono::seconds(1)));

    track.push_back(
        PositionSample(
            Position(1.0, 1.0),
            now + std::chrono::seconds(2)));

    auto series =
        Movement::courseSeries(track);

    REQUIRE(series.size() == 2);

    REQUIRE_THAT(
    series[0],
    Catch::Matchers::WithinAbs(0.0, 0.1));

    REQUIRE_THAT(
    series[1],
    Catch::Matchers::WithinAbs(90.0, 0.1));
}