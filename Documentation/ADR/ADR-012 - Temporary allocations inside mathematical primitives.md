# ADR-012 — Temporary Allocations in Mathematical Primitives

## Status

Accepted

---

## Context

GeoCore aims to provide lightweight, reusable mathematical primitives with
predictable behaviour and minimal overhead.

Most mathematical algorithms operate directly on user-provided data through
`std::span`, avoiding copies and dynamic memory allocations whenever possible.

However, some algorithms require temporary reordering of the input data.
Examples include circular statistics where values must be sorted to compute
properties such as the minimal circular range.

Because `std::span` provides a non-owning view, modifying the caller's data
would violate the immutability guarantees expected from GeoCore's public API.

---

## Decision

Mathematical primitives may perform a local temporary allocation when all of
the following conditions are met:

- the allocation is strictly local to the function;
- it is required to preserve the immutability of the input;
- it significantly simplifies the implementation;
- no equally simple allocation-free alternative exists;
- the allocation does not introduce observable side effects.

The preferred approach is to copy the input into a temporary container,
perform the required processing, and discard the temporary storage before
returning.

---

## Consequences

### Advantages

- Preserves immutable public APIs.
- Keeps implementations simple and maintainable.
- Avoids exposing unnecessary constraints to library users.
- Improves readability of mathematical algorithms.

### Drawbacks

- Introduces a temporary dynamic allocation.
- May have a small performance cost for very large datasets.

This trade-off is considered acceptable because the computational complexity
of algorithms such as sorting (`O(n log n)`) dominates the allocation cost,
and the expected dataset sizes in GeoCore remain moderate.

---

## Alternatives Considered

### Mutate caller-provided data

Rejected.

Public mathematical primitives should never modify user-owned containers.

### Require pre-sorted input

Rejected.

Sorting is an implementation detail and should not be imposed on library
users.

### Implement custom allocation-free sorting

Rejected.

The additional complexity is not justified for the intended use cases and
would reduce maintainability.

---

## Related Components

- Math::CircularRange
- Future circular statistics algorithms