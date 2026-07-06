# GC-0041 — NormalizeAngle

## Status

Implemented

---

## Goal

Provide a reusable mathematical primitive that normalizes any angle to its canonical representation in the interval:

[0°, 360°)

This capability serves as the foundation for all future angle-related algorithms.

---

## Motivation

Many geospatial algorithms manipulate angular values.

Normalizing angles in a single reusable function avoids duplicated logic and guarantees consistent behavior across GeoCore.

---

## API

```cpp
double normalizeAngle(double angle);