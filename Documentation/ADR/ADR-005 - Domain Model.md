# DR-005 – Domain Model

| Field | Value |
|-------|-------|
| Version | 0.1 |
| Status | Draft |
| Created | 2026-06-27 |
| Last Updated | 2026-06-27 |
| Authors | Zang, ChatGPT |

---

# Purpose

This document defines the domain model of the GeoCore Engine.

It describes the meaning, responsibilities and lifecycle of every core object manipulated by the engine.

The purpose of this document is not to describe implementation details, but to establish a common language shared by the entire project.

Every software component, simulator, firmware implementation and hardware integration must use the concepts defined here.

---

# Domain Model Philosophy

The GeoCore Engine is built around domain concepts rather than hardware components.

Every object exists because it represents a concept of the decision process.

Objects describe **what exists**, not **how it is implemented**.

The implementation language, hardware platform and communication protocols must never influence the domain model.

---

# Core Domain Objects

The first version of GeoCore defines six fundamental domain objects.

```
Configuration

↓

WorldState

↓

Zone

↓

Rule

↓

Action

↓

Position
```

Additional objects may be introduced in future versions without changing the existing concepts.

---

# Configuration

## Purpose

Configuration represents every persistent parameter required by the engine.

It defines how the engine should behave.

## Responsibilities

- Store zones.
- Store rules.
- Store engine parameters.
- Store system configuration.

## Lifecycle

Persistent.

Loaded before the engine starts.

Read-only during processing.

## Owner

Configuration System.

---

# WorldState

## Purpose

WorldState represents the complete understanding of the environment during one processing cycle.

It is the communication medium shared by every processing system.

## Responsibilities

- Store current observations.
- Store intermediate results.
- Store processing results.
- Store pending actions.

## Lifecycle

Runtime only.

Created or refreshed at the beginning of every processing cycle.

Destroyed or reset at the end of the cycle.

## Owner

Processing Cycle.

---

# Zone

## Purpose

A Zone describes a geographical area.

Zones define where rules apply.

## Responsibilities

- Store geometric boundaries.
- Define zone properties.
- Associate rules with locations.

## Lifecycle

Persistent.

Part of the Configuration.

## Owner

Configuration.

---

# Rule

## Purpose

A Rule transforms a situation into a decision.

Rules never perform calculations.

They evaluate information already available inside the WorldState.

## Responsibilities

- Evaluate conditions.
- Produce decisions.
- Generate actions.

## Lifecycle

Persistent.

Part of the Configuration.

## Owner

Configuration.

---

# Action

## Purpose

An Action represents a request produced by the engine.

Actions describe **what should happen**, never **how it should happen**.

## Responsibilities

- Represent requested behaviour.
- Describe execution parameters.
- Remain hardware independent.

## Lifecycle

Runtime only.

Produced during one processing cycle.

Consumed by the Output System.

## Owner

Action System.

---

# Position

## Purpose

Position represents the current spatial location known by the engine.

The Position object is independent from any GPS technology.

## Responsibilities

- Represent geographical coordinates.
- Represent positioning quality.
- Represent movement information.

## Lifecycle

Runtime only.

Updated every processing cycle.

## Owner

Input System.

---

# Object Relationships

```
Configuration

├── Zones

├── Rules

└── Parameters


↓

Processing Cycle


↓

WorldState

├── Inputs

├── Geometry

├── Rules

├── Safety

└── Actions
```

Persistent objects never depend on runtime objects.

Runtime objects never modify persistent objects.

---

# Design Rules

Every domain object follows the same principles.

- One responsibility.
- Explicit ownership.
- Clear lifecycle.
- Hardware independence.
- Simulator compatibility.
- Platform independence.

---

# Future Evolution

Future versions may introduce additional domain objects.

New objects must satisfy the same design principles and integrate naturally into the existing domain model.

The introduction of a new object must never invalidate the responsibilities of existing objects.

---

# Related Documents

- DR-003 – Architecture
- DR-004 – GeoCore Engine
- DR-006 – Hardware
- DR-010 – Glossary