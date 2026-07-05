add_executable(GeoCoreTests
    Math/DistanceTests.cpp
    Math/BearingTests.cpp
    Math/SpeedTests.cpp
    Geometry/PolygonTests.cpp
    Geometry/CircleTests.cpp
    Core/TrackTests.cpp
    Tracking/TrackingDistanceTests.cpp
    Math/MidpointTests.cpp
    Geometry/RectangleTests.cpp
    Math/DestinationTests.cpp
    Tracking/DurationTests.cpp
    Tracking/AverageSpeedTests.cpp
    Movement/StationaryTests.cpp
    Movement/AccelerationTests.cpp
)

target_link_libraries(GeoCoreTests
    PRIVATE
        GeoCore
        Catch2::Catch2WithMain
)

include(Catch)

catch_discover_tests(GeoCoreTests)