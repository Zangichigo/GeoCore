add_executable(GeoCoreTests

    Core/TrackTests.cpp

    Geometry/PolygonTests.cpp
    Geometry/CircleTests.cpp
    Geometry/RectangleTests.cpp

    Math/MidpointTests.cpp
    Math/NormalizeAngleTests.cpp
    Math/DistanceTests.cpp
    Math/BearingTests.cpp
    Math/SpeedTests.cpp
    Math/DestinationTests.cpp
    Math/NormalizeSignedAngleTests.cpp

    Tracking/TrackingDistanceTests.cpp
    Tracking/DurationTests.cpp
    Tracking/AverageSpeedTests.cpp

    Movement/StationaryTests.cpp
    Movement/AccelerationTests.cpp
    Movement/CourseTests.cpp
    Movement/CourseSeriesTests.cpp
)

target_link_libraries(GeoCoreTests
    PRIVATE
        GeoCore
        Catch2::Catch2WithMain
)

include(Catch)

catch_discover_tests(GeoCoreTests)