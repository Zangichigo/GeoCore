# GC-0048 — CircularRange

## Status

Planned

---

## Goal

Introduce a reusable mathematical primitive computing the minimal angular
range covering a set of circular values.

---

## Motivation

Arithmetic ranges fail for circular quantities.

Example:

359°
1°

Arithmetic range:

358°

Circular range:

2°

---

## Public API

```cpp
namespace GeoCore::Math
{

[[nodiscard]]
double circularRange(
    std::span<const double> angles);

}
```

---

## Behaviour

Empty input:

0°

Single value:

0°

Returned range:

[0°, 180°]

---

## Dependencies

NormalizeAngle

CircularMean (optional)

---

## Tests

Empty input

Single angle

Simple sequence

Wraparound

Opposite directions

Non-normalized input

---

## Review Checklist

Reusable

Independent

No allocation

Fully unit tested