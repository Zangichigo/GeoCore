# ADR-0006 — Distinguish Course and Heading

## Status

Accepted

---

## Context

GeoCore computes movement exclusively from geospatial observations.

At the current stage, the library only receives:

- Positions
- Timestamps

No orientation sensor is available.

Examples of unavailable sensors include:

- Compass
- IMU
- Gyroscope
- Magnetometer

During the implementation of `Movement::heading()`, we identified an important ambiguity.

In many domains (aviation, robotics, marine navigation), the term *Heading* refers to the direction an object is facing.

However, the direction computed from two GPS positions is not necessarily the object's orientation.

An object may:

- move backwards,
- slide sideways,
- drift,
- move independently of its orientation.

Therefore, GPS observations alone cannot determine Heading.

---

## Decision

GeoCore distinguishes two different concepts.

### Course

Course is the direction of motion.

It is computed exclusively from consecutive positions.

Course is therefore a pure geospatial property.

Example:

```cpp
double course =
    Movement::course(previous, current);
```

---

### Heading

Heading represents the direction an object is facing.

Heading requires orientation data from external sensors.

GeoCore does not compute Heading.

Future extensions may expose Heading if orientation data is provided.

---

## Consequences

GeoCore remains independent of any specific hardware.

The library only exposes concepts that can be computed from spatial observations.

Behaviour interpretation and hardware-specific orientation remain outside GeoCore's scope.

---

## Rationale

GeoCore describes spatial data and motion.

It does not infer orientation that cannot be observed.

This keeps the API physically correct and universally applicable.