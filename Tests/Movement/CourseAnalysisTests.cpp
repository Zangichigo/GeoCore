#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <GeoCore/Movement/CourseAnalysis.hpp>
#include <GeoCore/Movement/CourseSeries.hpp>

#include <GeoCore/Track.hpp>

#include <chrono>

using namespace GeoCore;

TEST_CASE("CourseAnalysis mean of empty CourseSeries")
{
    Track track;

    auto series =
        Movement::courseSeries(track);

    auto analysis =
        Movement::CourseAnalysis::fromSeries(series);

    REQUIRE_THAT(
        analysis.mean(),
        Catch::Matchers::WithinAbs(0.0, 1e-6));
}

TEST_CASE("CourseAnalysis mean of single course")
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

    auto analysis =
        Movement::CourseAnalysis::fromSeries(series);

    REQUIRE_THAT(
        analysis.mean(),
        Catch::Matchers::WithinAbs(0.0, 0.1));
}

TEST_CASE("CourseAnalysis mean of two courses")
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

    auto analysis =
        Movement::CourseAnalysis::fromSeries(series);

    REQUIRE_THAT(
        analysis.mean(),
        Catch::Matchers::WithinAbs(45.0, 0.2));
}

