# GC-0035 — Destination

## Status

✅ Completed

---

## Objective

Compute the geographic destination reached from a starting position, a bearing and a travel distance.

This capability complements the existing geospatial primitives:

- Distance
- Bearing
- Midpoint

Together, they provide the fundamental operations required for geospatial navigation and analysis.

---

## Module

Math

---

## Public API

```cpp
Position destination(
    const Position& start,
    double bearing,
    double distance);
```

---

## Responsibilities

This capability computes the destination position on Earth's surface from:

- a starting position,
- an initial bearing,
- a travel distance.

It does not:

- compute routes,
- perform navigation,
- account for roads or obstacles.

---

## Dependencies

Depends on:

- Position
- GeoCore constants
- Math utilities

Does not depend on:

- Track
- Geometry
- Movement
- Tracking
- Formats

---

## Unit Tests

- Zero distance returns the starting position.
- Moving north increases latitude.
- Moving east changes longitude.
- Destination remains valid for long distances.
- Latitude and longitude remain within valid ranges.

---

## Demonstration

Show:

- Start position
- Bearing
- Distance
- Destination position

Example:

```
Destination test

Start      : Paris

Bearing    : 45°

Distance   : 1000 m

Result

Latitude  : ...

Longitude : ...
```

---

## Documentation

Update:

- Roadmap status

No README update required.

---

## Future Improvements

Possible future extensions:

- Rhumb-line destination
- Alternative Earth models
- Higher precision ellipsoidal calculations

---

## Review Checklist

- [x] Architecture validated
- [x] Public API reviewed
- [x] Compiles successfully
- [x] Unit tests added
- [x] Demo updated
- [x] Documentation updated
- [x] GitHub Actions successful

---

## Notes

This capability completes the first set of fundamental geospatial mathematical operations provided by GeoCore.