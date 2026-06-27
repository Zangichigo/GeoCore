# GeoCore Modules

This document describes the functional modules of GeoCore.

A module represents a coherent set of geospatial capabilities.

---

## Geometry

Purpose:
Perform geometric and geographic calculations.

Current capabilities:

* [x] Distance
* [x] Circle containment
* [ ] Polygon containment
* [ ] Rectangle containment
* [ ] Bearing
* [ ] Projection

---

## Geofencing

Purpose:
Determine relationships between positions and geographic zones.

Current capabilities:

* [x] Zone
* [x] Zone membership
* [ ] Zone entry detection
* [ ] Zone exit detection
* [ ] Time spent inside
* [ ] Multiple simultaneous zones

---

## Movement

Purpose:
Analyze object movement over time.

Planned capabilities:

* [ ] Position history
* [ ] Speed
* [ ] Heading
* [ ] Acceleration
* [ ] Stationary detection

---

## Tracking

Purpose:
Provide higher-level tracking information.

Planned capabilities:

* [ ] Route history
* [ ] Distance travelled
* [ ] Route deviation
* [ ] Statistics

---

## Simulation

Purpose:
Replay recorded movements.

Planned capabilities:

* [ ] GPX replay
* [ ] CSV replay
* [ ] Simulation clock

---

## Extensibility

Purpose:
Allow applications to extend GeoCore.

Planned capabilities:

* [ ] Custom analyzers
* [ ] Plugin API
