add_library(GeoCore STATIC
    Source/Version.cpp
    Source/Position.cpp
    Source/WorldState.cpp
    Source/Engine.cpp
    Source/Circle.cpp
    Source/Polygon.cpp
    Source/Math/Distance.cpp
    Source/Zone.cpp
    Source/ProcessingResult.cpp
    Source/ProcessingContext.cpp
    Source/Geofencing.cpp
    Source/Math/Bearing.cpp
    Source/PositionSample.cpp
    Source/PositionHistory.cpp
    Source/Math/Speed.cpp
    Source/Units.cpp
)

target_include_directories(GeoCore
    PUBLIC
        Include
)

target_compile_features(GeoCore
    PUBLIC
        cxx_std_23
)