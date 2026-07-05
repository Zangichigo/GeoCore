# GC-0038 — Stationary Detection

## Status

🚧 In Progress

---

## Objective

Determine whether a track remained stationary during a minimum period of time.

---

## Module

Movement

---

## Public API

```cpp
[[nodiscard]]
bool stationary(
    const Track& track,
    double radiusMeters,
    std::chrono::seconds minimumDuration);
```

---

## Responsibilities

Return `true` if:

- the elapsed time is greater than or equal to `minimumDuration`;
- the distance between the first and last sample is less than or equal to `radiusMeters`.

Otherwise return `false`.

---

## Dependencies

- Math::distance()
- Tracking::duration()

---

## Unit Tests

- Empty track
- One sample
- Duration too short
- Radius exceeded
- Stationary track

---

## Demonstration

Demonstrate a stationary and a moving track.

---

## Future Improvements

Future versions may analyse all intermediate samples instead of only the first and last positions.

---

## Review Checklist

- [ ] Architecture validated
- [ ] Public API reviewed
- [ ] Compiles successfully
- [ ] Unit tests added
- [ ] Demonstration updated
- [ ] Documentation updated