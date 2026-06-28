add_executable(GeoCoreTests
    Math/DistanceTests.cpp
    Math/BearingTests.cpp
    Math/SpeedTests.cpp
    Geometry/PolygonTests.cpp
    Geometry/CircleTests.cpp
)

target_link_libraries(GeoCoreTests
    PRIVATE
        GeoCore
        Catch2::Catch2WithMain
)

include(Catch)

catch_discover_tests(GeoCoreTests)