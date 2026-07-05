# GC-0036 — Track Duration

## Status

🚧 In Progress

---

## Objective

Compute the elapsed time between the first and the last sample of a track.

This capability complements the existing tracking operations.

---

## Module

Tracking

---

## Public API

```cpp
[[nodiscard]]
std::chrono::system_clock::duration duration() const;
```

---

## Responsibilities

Return the elapsed duration represented by the track.

Rules:

- Empty track → zero duration.
- One sample → zero duration.
- Multiple samples → last timestamp minus first timestamp.

---

## Dependencies

Depends on:

- PositionSample
- Track

Does not depend on:

- Geometry
- Movement
- Geofencing

---

## Unit Tests

- Empty track returns zero.
- One sample returns zero.
- Two samples return correct duration.
- Duration increases as samples are added.

---

## Demonstration

Display:

- Number of samples
- Duration in seconds

---

## Documentation

No documentation update required.

---

## Future Improvements

Will be used by:

- Average Speed
- Movement Statistics

---

## Review Checklist

- [ ] Architecture validated
- [ ] Public API reviewed
- [ ] Compiles successfully
- [ ] Unit tests added
- [ ] Demonstration updated
- [ ] Documentation updated
- [ ] GitHub Actions successful