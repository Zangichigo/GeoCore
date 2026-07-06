#include <GeoCore/Engine.hpp>

#include <GeoCore/Circle.hpp>
#include <GeoCore/Polygon.hpp>
#include <GeoCore/Rectangle.hpp>
#include <GeoCore/Zone.hpp>
#include <GeoCore/Geofencing.hpp>

#include <GeoCore/Track.hpp>
#include <GeoCore/PositionSample.hpp>

#include <GeoCore/Math/Bearing.hpp>
#include <GeoCore/Math/Destination.hpp>
#include <GeoCore/Math/Midpoint.hpp>
#include <GeoCore/Math/Speed.hpp>
#include <GeoCore/Math/NormalizeAngle.hpp>
#include <GeoCore/Math/NormalizeSignedAngle.hpp>

#include <GeoCore/Units.hpp>

#include <chrono>
#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>

#include <GeoCore/Tracking/Duration.hpp>
#include <GeoCore/Tracking/AverageSpeed.hpp>

#include <GeoCore/Movement/Stationary.hpp>
#include <GeoCore/Movement/Acceleration.hpp>
#include <GeoCore/Movement/Course.hpp>

int main()
{
    using namespace GeoCore;

    //------------------------------------------------------------------
    // Common positions
    //------------------------------------------------------------------

    Position paris(48.8566, 2.3522);
    Position london(51.5074, -0.1278);
    Position lyon(45.7640, 4.8357);

    //------------------------------------------------------------------
    // Engine / Circle
    //------------------------------------------------------------------

    Engine engine;

    engine.addZone(
        Zone(
            "Home",
            std::make_unique<Circle>(
                paris,
                100.0)));

    WorldState state(
        Position(48.8567, 2.3523));

    ProcessingResult engineResult =
        engine.process(state);

    std::cout
    << std::boolalpha
    << std::fixed
    << std::setprecision(2);
    
    std::cout << "\n=== Engine / Circle ===\n";

    std::cout
        << "Inside : "
        << engineResult.inside()
        << '\n';

    //------------------------------------------------------------------
    // Zone transition
    //------------------------------------------------------------------

    std::cout << "\n=== Zone Transition ===\n";

    std::cout
        << "Outside -> Inside : "
        << static_cast<int>(
            detectTransition(
                ZoneMembership::Outside,
                ZoneMembership::Inside))
        << '\n';



    //------------------------------------------------------------------
    // Polygon
    //------------------------------------------------------------------

    Polygon garden(
    {
        {0.0, 0.0},
        {0.0, 10.0},
        {10.0, 10.0},
        {10.0, 0.0}
    });

    std::cout << "\n=== Polygon ===\n";

    std::cout
        << "Inside (5,5)   : "
        << garden.contains(Position(5.0, 5.0))
        << '\n';

    std::cout
        << "Outside (15,5) : "
        << garden.contains(Position(15.0, 5.0))
        << '\n';


   

    //------------------------------------------------------------------
    // PositionSample
    //------------------------------------------------------------------

    PositionSample sample(
        paris,
        std::chrono::system_clock::now());

    std::cout << "\n=== PositionSample ===\n";

    std::cout << std::setprecision(6);

    std::cout
        << "Latitude  : "
        << sample.position().latitude()
        << '\n';

    std::cout
        << "Longitude : "
        << sample.position().longitude()
        << '\n';

    std::cout << std::setprecision(2);   



auto trackStart = std::chrono::system_clock::now();
auto trackEnd   = trackStart + std::chrono::hours(5);

    //------------------------------------------------------------------
    // Track
    //------------------------------------------------------------------

Track track;

track.push_back(
    PositionSample(
        paris,
        trackStart));

track.push_back(
    PositionSample(
        lyon,
        trackEnd));

std::cout << "\n=== Track ===\n";

std::cout
    << "Size      : "
    << track.size()
    << '\n';

std::cout
    << "First lat : "
    << track.front().position().latitude()
    << '\n';

std::cout
    << "Last lat  : "
    << track.back().position().latitude()
    << '\n';
        
        

    //------------------------------------------------------------------
    // Bearing
    //------------------------------------------------------------------

    std::cout << "\n=== Bearing ===\n";

    std::cout
        << "Paris -> London : "
        << Math::bearing(paris, london)
        << "°\n";

    std::cout
        << "Paris -> Lyon   : "
        << Math::bearing(paris, lyon)
        << "°\n";




    //------------------------------------------------------------------
    // Speed
    //------------------------------------------------------------------

    PositionSample sample2(
        Position(48.8576, 2.3532),
        sample.timestamp() + std::chrono::seconds(10));

    double speedMs =
        Math::speed(sample, sample2);

    std::cout << "\n=== Speed ===\n";

    std::cout
        << speedMs
        << " m/s ("
        << Units::toKmh(speedMs)
        << " km/h, "
        << Units::toMph(speedMs)
        << " mph)\n";

        

    //------------------------------------------------------------------
    // Destination
    //------------------------------------------------------------------

    Position destination =
        Math::destination(
            paris,
            45.0,
            1000.0);

    std::cout << "\n=== Destination ===\n";

    std::cout
        << "Start      : Paris\n";

    std::cout
        << "Bearing    : 45°\n";

    std::cout
        << "Distance   : 1000 m\n";

    std::cout << std::fixed << std::setprecision(6);
        
    std::cout
        << "Latitude   : "
        << destination.latitude()
        << '\n';

    std::cout
        << "Longitude  : "
        << destination.longitude()
        << '\n';


    //------------------------------------------------------------------
    // Tracking
    //------------------------------------------------------------------

std::cout << "\n=== Tracking ===\n";

auto trackDuration =
    Tracking::duration(track);

std::cout
    << "Duration      : "
    << std::chrono::duration_cast<std::chrono::seconds>(trackDuration).count()
    << " s\n";

double average =
    Tracking::averageSpeed(track);

std::cout
    << "Average speed : "
    << average
    << " m/s ("
    << Units::toKmh(average)
    << " km/h, "
    << Units::toMph(average)
    << " mph)\n";



//------------------------------------------------------------------
// Course
//------------------------------------------------------------------

std::cout << "\n=== Course ===\n";

double currentCourse =
    Movement::course(
        sample,
        sample2);

std::cout
    << "Course : "
    << currentCourse
    << "°\n";


//------------------------------------------------------------------
// Movement
//------------------------------------------------------------------

std::cout << "\n=== Movement ===\n";

Track stationaryTrack;

auto start = std::chrono::system_clock::now();

stationaryTrack.push_back(
    PositionSample(
        Position(48.856600, 2.352200),
        start));

stationaryTrack.push_back(
    PositionSample(
        Position(48.856602, 2.352201),
        start + std::chrono::seconds(60)));

bool isStationary =
    Movement::stationary(
        stationaryTrack,
        5.0,
        std::chrono::seconds(30));

std::cout
    << "Stationary    : "
    << std::boolalpha
    << isStationary
    << '\n';

auto t0 = std::chrono::system_clock::now();

PositionSample a(
    Position(48.856600, 2.352200),
    t0);

PositionSample b(
    Position(48.856650, 2.352250),
    t0 + std::chrono::seconds(10));

PositionSample c(
    Position(48.857000, 2.352600),
    t0 + std::chrono::seconds(20));

double accel =
    Movement::acceleration(a, b, c);

std::cout
    << "Acceleration  : "
    << accel
    << " m/s²\n";


    //------------------------------------------------------------------
    // Angles
    //------------------------------------------------------------------
    
std::cout << "\n=== Normalize Angle ===\n";

std::cout << "370°  -> " << Math::normalizeAngle(370.0) << "°\n";
std::cout << "-20°  -> " << Math::normalizeAngle(-20.0) << "°\n";
std::cout << "720°  -> " << Math::normalizeAngle(720.0) << "°\n";

 
    //------------------------------------------------------------------
    // Normalize Signed Angle
    //------------------------------------------------------------------

std::cout << "\n=== Normalize Signed Angle ===\n";

std::cout << "181 deg   -> "
          << Math::normalizeSignedAngle(181.0)
          << " deg\n";

std::cout << "270 deg   -> "
          << Math::normalizeSignedAngle(270.0)
          << " deg\n";

std::cout << "-270 deg  -> "
          << Math::normalizeSignedAngle(-270.0)
          << " deg\n";
    
    return 0;
}