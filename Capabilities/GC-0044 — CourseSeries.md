# GC-0044 — CourseSeries

## Status

Planned

---

## Goal

Introduce a `CourseSeries` object representing the sequence of movement courses computed from a `Track`.

A `CourseSeries` is a temporal observation derived from successive position samples.

It contains no interpretation and performs no analysis.

---

## Motivation

GeoCore currently computes the course between two consecutive `PositionSample` objects.

Many future algorithms require the evolution of course over an entire trajectory rather than isolated values.

Examples include:

- course stability
- course variation
- future temporal analysis
- circular statistics

A dedicated object provides a reusable foundation for these future capabilities.

---

## Public API

```cpp
namespace GeoCore::Movement
{

class CourseSeries
{
public:

    bool empty() const;

    std::size_t size() const;

    double operator[](std::size_t index) const;

    const std::vector<double>& values() const;

};

CourseSeries courseSeries(const Track& track);

}
```

---

## Design

Given a Track containing:

P0
P1
P2
P3

The resulting CourseSeries contains:

Course(P0,P1)

Course(P1,P2)

Course(P2,P3)

Therefore:

CourseSeries size = Track size − 1

---

## Responsibilities

CourseSeries only stores computed course observations.

It does not:

- compute statistics
- detect turns
- infer rotations
- classify movement

Those responsibilities belong to future analysis capabilities.

---

## Dependencies

- Track
- PositionSample
- Course

---

## Future Users

- CourseAnalysis
- Circular statistics
- Temporal observation algorithms

---

## Tests

- empty track
- single sample
- two samples
- multiple samples
- insertion order
- operator[]
- values()

---

## Review Checklist

- Immutable observation object
- No movement interpretation
- Preserves computation order
- Fully unit tested