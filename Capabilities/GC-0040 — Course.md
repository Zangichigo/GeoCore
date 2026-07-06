# GC-0040 — course

## Status

🚧 In Progress

---

## Objective

Compute the current course of a moving object from two consecutive position samples.

---

## Module

Movement

---

## Public API

```cpp
[[nodiscard]]
double course(
    const PositionSample& previous,
    const PositionSample& current);
```

---

## Responsibilities

Return the current course in degrees.

course is expressed in the range:

- 0° = North
- 90° = East
- 180° = South
- 270° = West

---

## Dependencies

- Math::bearing()

---

## Unit Tests

- course north
- course east
- course south
- course west

---

## Demonstration

Display the course of a moving object.

---

## Future Improvements

Future versions may expose cardinal directions
(N, NE, E, SE, S, SW, W, NW).

---

## Review Checklist

- [ ] Architecture validated
- [ ] API reviewed
- [ ] Tests added
- [ ] Demo updated
- [ ] Documentation updated
- [ ] CHANGELOG updated