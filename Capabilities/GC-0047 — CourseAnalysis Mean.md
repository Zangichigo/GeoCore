# GC-0047 — CourseAnalysis Mean

## Status

Planned

---

## Goal

Extend `CourseAnalysis` with the circular mean of the observed courses.

The computation relies on the reusable mathematical primitive
`Math::circularMean`.

---

## Motivation

CourseAnalysis currently exposes:

- minimum
- maximum
- range

Providing the mean direction completes the first level of descriptive
statistics for movement courses.

Because headings are circular quantities, the arithmetic mean cannot be used.

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

    [[nodiscard]]
    double mean() const noexcept;

};

}
```

---

## Dependencies

Math::circularMean

---

## Responsibilities

CourseAnalysis aggregates statistics.

It does not implement circular mathematics.

---

## Tests

Empty CourseSeries

Single course

Multiple courses

Wraparound

---

## Review Checklist

Immutable

Uses CircularMean

No duplicated algorithms

Fully unit tested