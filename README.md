# GeoCore

# GeoCore

> **Turning location into spatial knowledge.**

![C++](https://img.shields.io/badge/C%2B%2B-20-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Tests](https://img.shields.io/badge/tests-59%2F59%20passing-brightgreen)
![Platform](https://img.shields.io/badge/platform-cross--platform-lightgrey)


GeoCore is a modern, lightweight and hardware-agnostic C++ geospatial engine.

It provides reusable geospatial objects and algorithms for applications that need to process spatial information.

GeoCore focuses on simplicity, consistency and long-term maintainability.

---

# Why GeoCore?

Excellent geospatial libraries already exist.

Many of them are extremely powerful, but they often target a very broad range of use cases and come with significant complexity.

GeoCore follows a different philosophy.

It intentionally focuses on the most common geospatial operations while keeping its API intuitive, lightweight and enjoyable to use.

GeoCore is not designed to replace large geospatial frameworks.

It is designed to become a clean and reliable foundation for modern geospatial applications.

---

# Features

## Core

- Position
- PositionSample
- Track
- Zone
- WorldState

## Math

- Distance
- Bearing
- Midpoint
- Destination *(planned)*
- Interpolation *(planned)*

## Geometry

- Circle
- Polygon
- Rectangle
- Polyline *(planned)*

## Movement

- Speed
- Course
- CourseSeries
- Acceleration
- Stationary Detection

## Tracking

- Track Distance
- Track Duration *(planned)*
- Average Speed *(planned)*

---

# Philosophy

GeoCore is built around a few simple principles.

- Keep the API simple.
- Keep responsibilities separated.
- Stay hardware independent.
- Stay business independent.
- Prefer stability over feature count.

More information can be found in the project documentation.

---

# Example

```cpp
using namespace GeoCore;

Position paris(48.8566, 2.3522);
Position london(51.5074, -0.1278);

double distance = Math::distance(paris, london);

double bearing = Math::bearing(paris, london);

Position midpoint = Math::midpoint(paris, london);
```

Simple.

Readable.

Predictable.

---

# Project Structure

```
GeoCore/
│
├── Engine/
├── Demo/
├── Tests/
├── Documentation/
├── Capabilities/
├── Backlog/
└── .github/
```

---

## Architecture

GeoCore progressively transforms raw spatial observations into reusable knowledge.

```text
Position
    │
    ▼
PositionSample
    │
    ▼
Track
    │
    ├─────────────────────┐
    ▼                     ▼
CourseSeries        SpeedSeries (future)
    │                     │
    └──────────┬──────────┘
               ▼
      Observation Analysis
               ▼
 Application Interpretation
```

GeoCore intentionally separates observation from interpretation.

The library measures and exposes reusable spatial observations, while applications remain responsible for deciding what those observations mean.

---

# Documentation

The documentation is organized to help new contributors quickly understand the project.

Recommended reading order:

1. Getting Started
2. Manifesto
3. Design Principles
4. API Philosophy
5. Roadmap

Architecture decisions are documented separately using ADRs.

---

# Building

Configure:

```bash
cmake -B build
```

Build:

```bash
cmake --build build
```

---

# Running Tests

Run every unit test:

```bash
ctest --test-dir build
```

Every pull request should compile successfully and pass all tests.

---

## Design Philosophy

GeoCore focuses on observable geospatial information.

It computes values that can be directly derived from spatial observations, while avoiding assumptions about the physical behaviour of tracked objects.

Applications remain responsible for interpreting these observations according to their own domain.

---

# Project Goals

GeoCore aims to become a reusable geospatial engine for:

- Robotics
- GIS software
- Asset tracking
- Outdoor navigation
- Scientific simulations
- Smart-home applications
- Embedded systems

GeoCore itself remains independent from all of these domains.

---

# Out of Scope

GeoCore intentionally does not include:

- Home Assistant integrations
- MQTT
- Zigbee
- LoRa
- GPS hardware drivers
- User interfaces
- Cloud services

These belong to applications built on top of GeoCore.

---

# Quality

GeoCore emphasizes software quality through:

- Unit tests
- Continuous Integration
- Architecture Decision Records (ADR)
- Living demonstrations
- Consistent API design
- Comprehensive documentation

---

# Roadmap

The current development roadmap is available in:

```
Documentation/5.Roadmap.md
```

---

GeoCore Progress

✓ Geometry
✓ Tracking
✓ Mathematical Foundations
✓ Movement Foundations
✓ Temporal Observation Foundations

Current capabilities
--------------------

✓ Distance
✓ Duration
✓ AverageSpeed
✓ Speed
✓ Course
✓ Acceleration
✓ Stationary

Tests

59/59 passing

Architecture

✓ ADR-009
✓ API Guidelines
✓ Coding Style


# Contributing

Contributions are welcome.

Before opening a Pull Request, please read:

- CONTRIBUTING.md
- Documentation/1.GettingStarted.md
- Documentation/6.CapabilityTemplate.md

Every contribution should include:

- Source code
- Unit tests
- Demonstration
- Documentation

---

# License

GeoCore is released under the MIT License.

See the LICENSE file for details.