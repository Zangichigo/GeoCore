# GC-0039 — Acceleration

## Status

🚧 In Progress

---

## Objective

Compute the average acceleration between two consecutive movement intervals.

---

## Module

Movement

---

## Public API

```cpp
[[nodiscard]]
double acceleration(
    const PositionSample& previous,
    const PositionSample& current,
    const PositionSample& next);
```

---

## Responsibilities

Return the average acceleration in meters per second squared (m/s²).

Acceleration is computed from the variation of speed between two consecutive intervals.

---

## Dependencies

- Math::speed()

---

## Unit Tests

- Identical timestamps
- Constant speed
- Positive acceleration
- Negative acceleration

---

## Demonstration

Display the computed acceleration between three position samples.

---

## Future Improvements

Future versions may support acceleration computed over an entire track.

---

## Review Checklist

- [ ] Architecture validated
- [ ] Public API reviewed
- [ ] Compiles successfully
- [ ] Unit tests added
- [ ] Demonstration updated
- [ ] Documentation updated