# GC-0042 — NormalizeSignedAngle

## Status

Implemented

---

## Goal

Provide a reusable mathematical primitive that normalizes any angle to its canonical signed representation in the interval:

(-180°, +180°]

This capability serves as the foundation for all signed angle computations throughout GeoCore.

---

## Motivation

Many geospatial algorithms require angular values expressed around zero rather than in the unsigned interval [0°, 360°).

Examples include:

- angular comparisons
- direction changes
- signed angle computations
- future temporal angle analysis

Keeping this responsibility isolated improves consistency and prevents duplicated normalization logic.

---

## API

```cpp
double normalizeSignedAngle(double angle);
```

---

## Examples

```text
normalizeSignedAngle(0)      ->    0
normalizeSignedAngle(45)     ->   45
normalizeSignedAngle(180)    ->  180
normalizeSignedAngle(181)    -> -179
normalizeSignedAngle(270)    ->  -90
normalizeSignedAngle(360)    ->    0
normalizeSignedAngle(540)    ->  180
normalizeSignedAngle(-181)   ->  179
normalizeSignedAngle(-270)   ->   90
normalizeSignedAngle(-360)   ->    0
```

---

## Design

NormalizeSignedAngle is built on top of NormalizeAngle.

The implementation first converts the angle into the interval:

[0°, 360°)

before mapping values greater than 180° into:

(-180°, +180°]

This ensures a single canonical representation for opposite directions.

For example:

```text
180°   -> 180°
-180°  -> 180°
540°   -> 180°
```

Only one value represents the opposite direction.

---

## Dependencies

- GC-0041 — NormalizeAngle

---

## Used By

- AngularDifference
- Future circular statistics
- Future temporal movement analysis

---

## Tests

The capability is validated through unit tests covering:

- zero angle
- positive values
- negative values
- ±180°
- values greater than 360°
- multiple complete rotations

---

## Review Checklist

- Correct signed interval
- Single representation of opposite directions
- No duplicated normalization logic
- Independent from movement concepts
- Fully unit tested