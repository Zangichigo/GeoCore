# DR-003 – Architecture

| Field | Value |
|-------|-------|
| Version | 0.1 |
| Status | Draft |
| Created | 2026-06-27 |
| Last Updated | 2026-06-27 |
| Authors | Zang, ChatGPT |

---

# Purpose

This document defines the software architecture of GeoCore.

Its objective is to describe how the different parts of the system interact, how responsibilities are separated and how the platform remains maintainable as it evolves.

This document intentionally avoids implementation details.

It focuses on architecture.

---

# Architectural Goals

GeoCore has been designed around six primary goals.

- Simplicity
- Reliability
- Modularity
- Testability
- Hardware Independence
- Local-First Operation

Every architectural decision must support at least one of these goals without compromising the others.

---

# Design Principles

## Separation of Concerns

Each module has one responsibility.

A module should never perform tasks outside its own domain.

---

## Deterministic Processing

For identical inputs, GeoCore must always produce identical outputs.

The system must never rely on unpredictable execution order.

---

## Local First

Every decision is made locally.

External services may provide configuration or monitoring but never participate in real-time decision making.

---

## Hardware Independence

The decision engine must never depend on a specific GPS receiver, microcontroller or communication technology.

Hardware can change without affecting the core engine.

---

## Simulation First

Every processing step should be executable inside the simulator before being deployed to embedded hardware.

The simulator and the firmware share the same processing logic.

---

# High-Level Architecture

GeoCore is organized as a deterministic processing pipeline.

Every processing cycle follows exactly the same sequence.

```
Configuration
        │
        ▼
Input
        │
        ▼
World State
        │
        ▼
Processing Systems
        │
        ▼
Actions
        │
        ▼
Outputs
```

This execution model guarantees predictable behaviour and simplifies testing.

---

# World State

The World State is the central data model of GeoCore.

Instead of modules communicating directly with each other, every processing system reads from and writes to the World State.

The World State represents the current understanding of the environment.

It progressively becomes richer as processing advances.

Typical information includes:

- Position
- Speed
- Heading
- GPS accuracy
- Battery level
- Active profile
- Zone information
- Geometry results
- Rule evaluation
- Safety evaluation
- Pending actions

The World State exists only during a processing cycle and is recreated or refreshed at every iteration.

---

# Processing Pipeline

Each execution cycle follows the same sequence.

1. Read inputs.
2. Update the World State.
3. Execute processing systems.
4. Generate actions.
5. Execute outputs.

This order never changes.

The pipeline architecture provides deterministic behaviour while remaining simple to understand and debug.

---

# Core Systems

GeoCore is divided into independent processing systems.

Each system has a single responsibility.

Each system only reads and writes the information it owns.

The systems never communicate directly.

Communication always occurs through the World State.

The first version of GeoCore contains the following systems:

- Configuration System
- Input System
- Geometry System
- Rule System
- Safety System
- Action System
- Output System
- Communication System

Detailed responsibilities are defined in DR-004.

---

# Dependency Rules

Dependencies always flow in one direction.

Higher-level systems may use lower-level systems.

Lower-level systems must never depend on higher-level logic.

For example:

```
Rule System
      │
      ▼
Geometry System
      │
      ▼
Mathematics
```

The reverse dependency is forbidden.

---

# Architecture Constraints

The following rules are mandatory.

- Modules communicate only through the World State.
- Processing systems remain deterministic.
- Hardware access is isolated from business logic.
- Business logic never controls hardware directly.
- Every processing system must be independently testable.
- No module owns more than one responsibility.

---

# Future Evolution

The architecture has been designed to support future extensions without modifying the core pipeline.

Possible future additions include:

- Multiple positioning technologies
- Additional sensors
- New communication protocols
- Multiple output devices
- Additional simulation tools

The processing pipeline remains unchanged.

---

# Related Documents

- DR-001 – Vision
- DR-002 – Roadmap
- DR-004 – GeoCore Engine
- DR-010 – Glossary