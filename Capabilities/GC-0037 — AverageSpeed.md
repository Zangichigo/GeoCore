# GC-0037 — Average Speed

## Status

🚧 In Progress

---

## Objective

Compute the average speed over a complete track.

---

## Module

Tracking

---

## Public API

```cpp
[[nodiscard]]
double averageSpeed(const Track& track);
```

---

## Responsibilities

Return the average speed in meters per second.

Rules:

- Empty track → 0.0
- One sample → 0.0
- Zero duration → 0.0
- Otherwise → total distance / total duration

---

## Dependencies

Depends on:

- Tracking::distance()
- Tracking::duration()

---

## Unit Tests

- Empty track
- One sample
- Zero duration
- Moving track

---

## Demonstration

Display:

- Distance
- Duration
- Average speed

---

## Future Improvements

This capability will serve as the basis for movement statistics.

---

## Review Checklist

- [ ] Architecture validated
- [ ] Public API reviewed
- [ ] Compiles successfully
- [ ] Unit tests added
- [ ] Demonstration updated
- [ ] Documentation updated