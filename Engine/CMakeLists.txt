add_library(GeoCore STATIC
    Source/Version.cpp
)

target_include_directories(GeoCore
    PUBLIC
        Include
)

target_compile_features(GeoCore
    PUBLIC
        cxx_std_23
)