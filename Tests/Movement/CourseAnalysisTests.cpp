#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Movement/CourseAnalysis.hpp>
#include <GeoCore/Movement/CourseSeries.hpp>

#include <GeoCore/Track.hpp>

#include <chrono>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

using namespace GeoCore;

TEST_CASE("CourseAnalysis of empty CourseSeries")
{
    Track track;

    auto series =
        Movement::courseSeries(track);

    auto analysis =
        Movement::courseAnalysis(series);

    REQUIRE(analysis.minimum() == 0.0);
    REQUIRE(analysis.maximum() == 0.0);
    REQUIRE(analysis.range() == 0.0);
}

TEST_CASE("CourseAnalysis minimum")
{
    Track track;

    auto now = std::chrono::system_clock::now();

    track.push_back(PositionSample(Position(0.0, 0.0), now));
    track.push_back(PositionSample(Position(1.0, 0.0), now + std::chrono::seconds(1)));
    track.push_back(PositionSample(Position(1.0, 1.0), now + std::chrono::seconds(2)));

    auto series =
        Movement::courseSeries(track);

    auto analysis =
        Movement::courseAnalysis(series);

    REQUIRE_THAT(
    analysis.minimum(),
    Catch::Matchers::WithinAbs(0.0, 0.1));
}

TEST_CASE("CourseAnalysis maximum")
{
    Track track;

    auto now = std::chrono::system_clock::now();

    track.push_back(PositionSample(Position(0.0, 0.0), now));
    track.push_back(PositionSample(Position(1.0, 0.0), now + std::chrono::seconds(1)));
    track.push_back(PositionSample(Position(1.0, 1.0), now + std::chrono::seconds(2)));

    auto series =
        Movement::courseSeries(track);

    auto analysis =
        Movement::courseAnalysis(series);

    REQUIRE_THAT(
    analysis.maximum(),
    Catch::Matchers::WithinAbs(90.0, 0.1));
}

TEST_CASE("CourseAnalysis range")
{
    Track track;

    auto now = std::chrono::system_clock::now();

    track.push_back(PositionSample(Position(0.0, 0.0), now));
    track.push_back(PositionSample(Position(1.0, 0.0), now + std::chrono::seconds(1)));
    track.push_back(PositionSample(Position(1.0, 1.0), now + std::chrono::seconds(2)));

    auto series =
        Movement::courseSeries(track);

    auto analysis =
        Movement::courseAnalysis(series);

    REQUIRE_THAT(
    analysis.range(),
    Catch::Matchers::WithinAbs(90.0, 0.1));
}

TEST_CASE("CourseAnalysis single course")
{
    Track track;

    auto now = std::chrono::system_clock::now();

    track.push_back(PositionSample(Position(0.0, 0.0), now));
    track.push_back(PositionSample(Position(1.0, 0.0), now + std::chrono::seconds(1)));

    auto series =
        Movement::courseSeries(track);

    auto analysis =
        Movement::courseAnalysis(series);

    REQUIRE_THAT(
    analysis.minimum(),
    Catch::Matchers::WithinAbs(0.0, 0.1));
    REQUIRE_THAT(
    analysis.maximum(),
    Catch::Matchers::WithinAbs(0.0, 0.1));

REQUIRE_THAT(
    analysis.range(),
    Catch::Matchers::WithinAbs(0.0, 0.1));
}