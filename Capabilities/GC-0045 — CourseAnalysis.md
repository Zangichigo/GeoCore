# GC-0045 — CourseAnalysis

## Status

Planned

---

## Goal

Introduce a `CourseAnalysis` object providing descriptive statistics computed
from a `CourseSeries`.

The object summarizes the observed movement courses without introducing any
application-specific interpretation.

---

## Motivation

While `CourseSeries` exposes the sequence of observed movement courses, many
applications require simple descriptive information about the overall series.

Providing a dedicated analysis object keeps statistical operations separate
from observation objects and follows the Observation Pipeline defined in
ADR-011.

---

## Public API

```cpp
namespace GeoCore::Movement
{

class CourseAnalysis
{
public:

    [[nodiscard]]
    double minimum() const noexcept;

    [[nodiscard]]
    double maximum() const noexcept;

    [[nodiscard]]
    double range() const noexcept;

};

[[nodiscard]]
CourseAnalysis courseAnalysis(
    const CourseSeries& series);

}
```

---

## Design

`CourseAnalysis` is immutable.

All statistics are computed during construction.

The object only exposes read-only accessors.

---

## Responsibilities

CourseAnalysis provides descriptive information about a `CourseSeries`.

It does not:

- classify movement
- detect turns
- infer rotations
- interpret behaviour

---

## Dependencies

- CourseSeries

---

## Future Extensions

Future capabilities will extend CourseAnalysis with:

- circular mean
- circular variance
- dispersion
- stability metrics

---

## Tests

- empty CourseSeries
- single value
- multiple values
- minimum
- maximum
- range

---

## Review Checklist

- Immutable object
- No interpretation
- Independent from business logic
- Fully unit tested