# ADR-007 — Engine vs Extensions

- **Status:** Accepted
- **Date:** 2026-07-02

---

# Context

GeoCore is intended to become a reusable geospatial engine.

During the design of the project, several features such as GPX support, GeoJSON export and other exchange formats were considered.

A question naturally emerged:

Should these capabilities belong to the GeoCore engine itself?

After discussion, it became clear that these features have a different responsibility.

The engine manipulates geospatial concepts.

Formats simply convert those concepts to external representations.

---

# Decision

GeoCore is divided into two layers.

## Engine

The engine contains only geospatial concepts and algorithms.

Examples:

- Position
- PositionSample
- Track
- Circle
- Rectangle
- Polygon
- Zone

Algorithms:

- Distance
- Bearing
- Midpoint
- Speed
- Course

The engine must remain completely independent from:

- File formats
- Hardware
- Business domains
- External services

---

## Extensions

Extensions provide interoperability with external ecosystems.

Examples:

- GPX Reader
- GPX Writer
- GeoJSON
- CSV
- Future integrations

Extensions depend on GeoCore.

GeoCore never depends on extensions.

---

# Architecture

```
Applications

        ▲

OpenFence
GIS
Robotics
Simulation
Research
Navigation

────────────────────────────

Extensions

GPX
GeoJSON
CSV
...

────────────────────────────

GeoCore Engine

Core
Math
Geometry
Movement
Tracking
```

---

# Rationale

This separation keeps the engine focused on one responsibility:

Providing reusable geospatial objects and algorithms.

External technologies evolve independently.

Keeping them outside the engine provides:

- simpler APIs
- fewer dependencies
- better maintainability
- smaller builds
- easier testing

---

# Consequences

GeoCore remains lightweight.

Applications can choose only the extensions they need.

Examples:

Application A

GeoCore

↓

Track

↓

Analysis

Application B

GeoCore

+

GPX Extension

↓

Import GPX

↓

Track

↓

Analysis

Application C

GeoCore

+

GeoJSON Extension

↓

Export Polygon

Applications remain free to combine extensions.

---

# Alternatives Considered

## Include formats inside the engine

Rejected.

Reasons:

- Increased complexity.
- Additional dependencies.
- Mixed responsibilities.
- Harder maintenance.

---

## Separate engine and extensions

Accepted.

This solution respects the Single Responsibility Principle and keeps GeoCore independent from external technologies.

---

# Future

New extensions should never modify the engine architecture.

Instead, they should build on the stable public API provided by GeoCore.

Possible future extensions include:

- GPX
- GeoJSON
- CSV
- KML
- Python bindings
- ROS integration
- Qt integration

The engine remains unchanged.