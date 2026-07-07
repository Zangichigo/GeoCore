# GC-0046 — CircularMean

## Status

Planned

---

## Goal

Introduce a reusable mathematical primitive computing the circular mean of a
set of angular values expressed in degrees.

The function correctly handles angular wraparound and provides meaningful
results for circular data.

---

## Motivation

Arithmetic means are unsuitable for angular values.

For example:

359°

1°

have an arithmetic mean of:

180°

while their circular mean is:

0°

GeoCore requires a reusable implementation for future observation analyses.

---

## Public API

```cpp
namespace GeoCore::Math
{

[[nodiscard]]
double circularMean(
    std::span<const double> angles);

}
```

---

## Behaviour

Empty input returns:

0°

Input values may be outside the interval [0°, 360°).

The function internally normalizes all angles.

---

## Examples

Input

350°
10°

Result

0°

---

Input

90°
180°
270°

Result

180°

---

## Dependencies

NormalizeAngle

---

## Future Users

CourseAnalysis

Circular statistics

Wind direction

Compass analysis

Robotics

Navigation

---

## Tests

Empty input

Single angle

Two identical angles

Wraparound (359°, 1°)

Several angles

Non-normalized input

---

## Review Checklist

Reusable

Independent

No allocation

No business logic

Fully unit tested