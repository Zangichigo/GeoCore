# GC-0043 — Refactor AngularDifference

## Status

Implemented

---

## Goal

Refactor `angularDifference()` to reuse the `NormalizeSignedAngle` capability instead of implementing its own normalization logic.

This capability simplifies the implementation while preserving the existing public API and behavior.

---

## Motivation

The original implementation contained its own angle normalization algorithm.

With the introduction of `NormalizeSignedAngle`, this logic became duplicated.

GeoCore favors small reusable primitives over duplicated implementations.

By delegating normalization to a dedicated capability, the code becomes:

- simpler
- easier to understand
- easier to maintain
- consistent with the rest of the mathematical API

---

## Public API

No public API changes.

```cpp
double angularDifference(
    double angle1,
    double angle2);
```

---

## Implementation

Previous implementation:

- computes the angle difference
- performs normalization
- handles wrap-around

New implementation:

```cpp
return normalizeSignedAngle(angle2 - angle1);
```

The behavior remains unchanged.

Only the internal implementation has been simplified.

---

## Dependencies

- GC-0042 — NormalizeSignedAngle

---

## Benefits

- Removes duplicated normalization logic
- Single source of truth for signed angle normalization
- Smaller implementation
- Improved readability
- Easier future maintenance

---

## Impact

This capability introduces no behavioral changes.

All existing unit tests continue to validate the public behavior of `angularDifference()`.

Only the internal implementation has changed.

---

## Tests

No new unit tests were required.

Existing `AngularDifference` tests continue to pass without modification, demonstrating that the refactoring preserves the original behavior.

---

## Review Checklist

- Public API unchanged
- No behavioral changes
- Uses NormalizeSignedAngle
- Removes duplicated code
- Existing tests pass