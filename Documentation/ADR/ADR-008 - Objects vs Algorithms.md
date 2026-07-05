# ADR-008 — Objects vs Algorithms

- **Status:** Accepted
- **Date:** 2026-07-02

---

# Context

GeoCore models geospatial concepts such as positions, shapes and trajectories.

During development, several API designs were considered.

For example:

```cpp
track.distance();

track.averageSpeed();

position.distanceTo(other);

polygon.computeArea();
```

versus

```cpp
Math::distance(a, b);

Tracking::distance(track);

Movement::speed(a, b);
```

A consistent design philosophy was required.

---

# Decision

GeoCore separates **objects** from **algorithms**.

Objects represent geospatial concepts.

Algorithms process these objects.

Both have different responsibilities and should remain separated whenever possible.

---

# Objects

Objects model real-world concepts.

Examples:

- Position
- PositionSample
- Track
- Circle
- Rectangle
- Polygon
- Zone

Objects own their data.

Objects may expose behavior that is intrinsic to their own state.

Examples:

```cpp
circle.contains(position);

polygon.contains(position);

track.empty();

track.size();
```

These operations naturally belong to the object itself.

---

# Algorithms

Algorithms operate on one or more objects.

Algorithms belong to dedicated namespaces.

Examples:

```cpp
Math::distance(a, b);

Math::bearing(a, b);

Math::midpoint(a, b);

Movement::speed(first, second);

Tracking::distance(track);
```

Algorithms should not become member functions when they do not naturally belong to the object's responsibility.

---

# Rationale

This separation provides several benefits.

## Clear responsibilities

Objects describe data.

Algorithms perform calculations.

Each component has one responsibility.

---

## Better maintainability

Objects remain lightweight.

Algorithm modules can evolve independently.

Adding a new algorithm rarely requires modifying existing classes.

---

## Reduced coupling

Tracking algorithms depend on Track.

Track does not depend on Tracking.

This keeps dependencies flowing in one direction.

---

## Easier extension

New algorithms can be introduced without modifying existing objects.

Example:

```cpp
Tracking::averageSpeed(track);

Tracking::duration(track);

Tracking::maximumSpeed(track);
```

Track itself remains unchanged.

---

# Exceptions

Some operations naturally belong to the object.

Examples:

```cpp
circle.contains(position);

polygon.contains(position);

rectangle.contains(position);
```

These methods answer a simple question about the object's own geometry.

They are therefore considered intrinsic behavior.

---

# Rejected Alternatives

## Rich objects ("God Objects")

Example:

```cpp
track.distance();

track.duration();

track.averageSpeed();

track.exportGPX();

track.sendMQTT();
```

Rejected.

Objects would progressively accumulate unrelated responsibilities.

---

## Utility classes

Example:

```cpp
GeometryUtils::distance(...);

TrackingUtils::speed(...);
```

Rejected.

Namespaces provide the same organization without introducing unnecessary classes.

---

# Consequences

GeoCore APIs remain predictable.

Objects expose only behaviors that naturally belong to them.

Algorithms are grouped by domain:

- Math
- Movement
- Tracking

This architecture scales well as new capabilities are introduced.

---

# Guideline

When introducing a new capability, ask the following question:

> "Does this behavior naturally belong to the object itself?"

If the answer is **yes**, it should probably become a member function.

If the answer is **no**, it should become a free function inside the appropriate namespace.

---

# Examples

Good:

```cpp
circle.contains(position);

polygon.contains(position);

track.size();

track.empty();

Math::distance(a, b);

Math::bearing(a, b);

Tracking::distance(track);

Movement::speed(first, second);
```

Avoid:

```cpp
track.distance();

track.averageSpeed();

position.distanceTo(other);

polygon.calculateAreaStatistics();
```

Such APIs mix data and processing responsibilities and make long-term maintenance more difficult.

---

# Summary

GeoCore follows a simple principle:

**Objects represent geospatial concepts.**

**Algorithms process geospatial concepts.**

Keeping these responsibilities separate results in a cleaner, more maintainable and more extensible API.