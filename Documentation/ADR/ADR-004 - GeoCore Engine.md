# DR-004 – GeoCore Engine

| Field | Value |
|-------|-------|
| Version | 0.1 |
| Status | Draft |
| Created | 2026-06-27 |
| Last Updated | 2026-06-27 |
| Authors | Zang, ChatGPT |

---

# Purpose

This document defines the design of the GeoCore processing engine.

The engine is responsible for transforming observations of the environment into deterministic decisions.

It is intentionally independent from any hardware platform or application domain.

This document describes the concepts, responsibilities and execution model of the engine.

Implementation details are intentionally omitted.

---

# Engine Philosophy

GeoCore is not a collection of algorithms.

It is a deterministic processing engine.

Every processing cycle follows the same sequence:

> **Observe → Understand → Decide → Act**

This execution model is the foundation of the entire project.

Every component of the engine exists to support one of these four stages.

---

# Processing Cycle

The engine continuously executes independent processing cycles.

Each cycle follows the same workflow.

```
Observe

↓

Understand

↓

Decide

↓

Act
```

The duration of a cycle depends on the execution environment.

The engine itself does not require a fixed frequency.

---

# Observe

The Observe stage collects information from the outside world.

Typical observations include:

- Position
- Velocity
- Course
- Time
- Battery state
- Sensor values

The engine does not know where these observations come from.

They may originate from:

- Embedded hardware
- A simulator
- Recorded data
- Unit tests

---

# Understand

The Understand stage transforms raw observations into meaningful information.

Examples include:

- Current zone
- Distance to boundary
- Nearest boundary
- Direction to boundary
- Position confidence

This stage performs calculations only.

No decisions are made.

---

# Decide

The Decide stage evaluates the current situation.

It applies configuration, rules and safety constraints.

Its responsibility is to determine which actions should be performed.

Examples:

- Generate a warning.
- Delay an action.
- Ignore unreliable data.
- Escalate an alert.

The Decide stage never interacts with hardware.

---

# Act

The Act stage produces executable actions.

Typical actions include:

- Play a sound.
- Trigger vibration.
- Activate an output.
- Generate an event.
- Notify external systems.

The engine requests actions.

It never executes them directly.

---

# World State

The World State is the central data model shared by every processing system.

It represents the current understanding of the environment.

Every processing system reads information from the World State and enriches it.

Processing systems never communicate directly.

The World State is refreshed at every processing cycle.

---

# Processing Systems

Each processing system has one responsibility.

Typical systems include:

- Input System
- Geometry System
- Rule System
- Safety System
- Action System
- Output System

Each system:

- reads specific information,
- produces new information,
- updates only its own domain.

---

# Domain Ownership

Every processing system owns one domain.

A processing system may only modify the information belonging to its own domain.

Cross-domain modifications are forbidden.

This rule guarantees predictable behaviour and simplifies maintenance.

---

# Actions

Actions represent the output of the decision engine.

An action describes **what** should happen.

It never describes **how** it should happen.

Execution is delegated to the Output System.

This separation allows the engine to remain hardware independent.

---

# Engine Characteristics

The GeoCore Engine is designed to be:

- Deterministic
- Testable
- Modular
- Hardware Independent
- Local First
- Simulator Compatible

---

# Non-Responsibilities

The engine is intentionally unaware of:

- GPS manufacturers
- Microcontrollers
- Communication protocols
- Home Assistant
- User interfaces
- Device-specific drivers

These responsibilities belong to other layers of the platform.

---

# Future Evolution

The engine architecture has been designed to support future processing systems without modifying the execution model.

New capabilities should integrate into the existing processing cycle rather than introducing alternative workflows.

---

# Related Documents

- DR-003 – Architecture
- DR-005 – Hardware
- DR-006 – Firmware
- DR-010 – Glossary