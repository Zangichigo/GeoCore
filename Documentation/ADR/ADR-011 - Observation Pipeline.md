# ADR-011 — Observation Pipeline

## Status

Accepted

---

## Context

GeoCore started as a geospatial computation library providing reusable
mathematical and geometric primitives.

As the project evolved, a new architectural pattern naturally emerged.

Rather than exposing isolated calculations, GeoCore progressively transforms
raw spatial observations into richer, reusable spatial knowledge.

To preserve a clean architecture and avoid introducing application-specific
logic, each transformation stage must have a clearly defined responsibility.

---

## Decision

GeoCore organizes spatial information into successive observation layers.

Each layer is responsible for a single transformation.

```
Position
    │
    ▼
PositionSample
    │
    ▼
Track
    │
    ├────────────────────┐
    ▼                    ▼
CourseSeries      SpeedSeries (future)
    │                    │
    └──────────┬─────────┘
               ▼
        Observation Analysis
               ▼
    Application Interpretation
```

---

## Layer 1 — Raw Observations

Raw observations directly represent measured spatial data.

Examples include:

- Position
- PositionSample
- Track

These objects never perform calculations beyond representing measured
information.

---

## Layer 2 — Derived Observations

Derived observations are computed from one or more raw observations.

Examples include:

- CourseSeries
- SpeedSeries (future)
- DistanceSeries (future)

Derived observations expose computed values without attaching any semantic
meaning.

They answer questions such as:

- "What were the successive movement courses?"
- "What were the measured speeds?"

They do **not** answer:

- "Was the object turning?"
- "Was the movement stable?"

---

## Layer 3 — Analysis

Analysis objects summarize one or more derived observations.

Examples include:

- CourseAnalysis
- SpeedAnalysis
- TrackAnalysis

Analysis objects expose descriptive properties such as:

- minimum
- maximum
- mean
- variation
- dispersion

Analysis never performs application-specific interpretation.

---

## Application Interpretation

GeoCore intentionally stops at observation.

The responsibility of assigning meaning belongs entirely to applications.

For example, GeoCore does **not** determine whether:

- a vehicle made a U-turn;
- an animal is hunting;
- a drone is circling;
- a user is walking or driving.

Applications remain free to interpret the observations according to their own
domain.

---

## Rationale

This separation provides several advantages.

### Predictability

Each layer has a single responsibility.

---

### Reusability

The same observations can be interpreted differently depending on the
application.

---

### Extensibility

New observation types can be introduced without modifying existing layers.

---

### Testability

Each layer can be tested independently.

---

### Domain Independence

GeoCore remains independent from any business logic or hardware platform.

---

## Consequences

Positive:

- simple architecture
- composable components
- reusable observations
- reusable analyses
- stable public API
- clear separation of responsibilities

Trade-offs:

- additional abstraction layers
- more small classes

These trade-offs are considered acceptable because they improve long-term
maintainability.

---

## Philosophy

GeoCore measures.

GeoCore observes.

Applications interpret.

This principle applies consistently throughout the entire library and serves as
one of the core architectural foundations of the project.