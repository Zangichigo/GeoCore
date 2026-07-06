# ADR-010 - Observed Motion vs Object Motion

- Status: Accepted
- Date: 2026-07-06

---

# Context

GeoCore computes geospatial information from a sequence of spatial observations.

During the design of movement-related capabilities, an important distinction emerged between:

- the observed movement derived from positions,
- the physical motion of the tracked object.

These two concepts must not be confused.

---

# Decision

GeoCore only models information that can be directly observed or computed from spatial samples.

GeoCore shall never infer the physical behaviour of an object when such information cannot be deduced from the available observations.

---

# Observable quantities

Examples include:

- Position
- Distance
- Bearing
- Course
- Speed
- Acceleration
- Stationary detection

These values are directly computed from spatial samples and timestamps.

---

# Non-observable quantities

Examples include:

- Heading
- Steering angle
- Wheel orientation
- Physical rotation
- Vehicle dynamics
- Object intent

These quantities require additional sensors or domain knowledge and therefore remain outside the scope of GeoCore.

---

# Course vs Heading

Course represents the direction of the observed displacement.

Heading represents the orientation of the object itself.

These values may differ.

Examples:

- a car reversing;
- a drone flying sideways;
- a boat drifting;
- a crab walking laterally.

GeoCore computes Course.

GeoCore does not compute Heading.

---

# Temporal observations

A single observation provides only the state of the movement at a given instant.

Movement analysis is based on a sequence of observations over time.

Capabilities analysing movement should therefore operate on temporal data rather than attempting to infer behaviour from isolated measurements.

---

# Design principle

GeoCore measures observations.

Applications interpret observations.

This separation keeps GeoCore:

- hardware independent;
- business independent;
- physically neutral;
- reusable across multiple domains.

---

# Consequences

Movement capabilities should describe observable trajectory evolution.

They should avoid implying physical object behaviour unless such behaviour is directly observable from the available data.

Future movement analysis should therefore focus on:

- course evolution;
- trajectory evolution;
- temporal analysis;

rather than object dynamics.