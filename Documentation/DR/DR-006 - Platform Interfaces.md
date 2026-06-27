# DR-006 – Platform Interfaces

| Field | Value |
|-------|-------|
| Version | 0.1 |
| Status | Draft |
| Created | 2026-06-27 |
| Last Updated | 2026-06-27 |
| Authors | Zang, ChatGPT |

---

# Purpose

This document defines the interfaces between the GeoCore Engine and the platform hosting it.

GeoCore never communicates directly with hardware.

Instead, every interaction with the outside world is performed through abstract platform interfaces.

This design allows the same engine to run on different targets without modification.

Examples include:

- Embedded devices
- Simulators
- Desktop applications
- Automated test environments

---

# Design Philosophy

GeoCore depends on capabilities.

It never depends on hardware.

A platform is responsible for providing these capabilities.

The engine remains completely unaware of how they are implemented.

---

# Platform Responsibilities

A platform provides everything required for the engine to execute one processing cycle.

Its responsibilities include:

- Providing observations.
- Executing requested actions.
- Loading configuration.
- Persisting data.
- Managing time.

Everything else belongs to the engine.

---

# Required Interfaces

Every compatible platform should provide the following interfaces.

## Position Provider

Provides the current position of the tracked object.

The implementation may use:

- GNSS
- Simulation
- Replay files
- Indoor positioning

GeoCore only receives a Position.

---

## Time Provider

Provides the current time.

The engine never accesses clocks directly.

---

## Configuration Provider

Loads the engine configuration.

Examples include:

- Local files
- Flash memory
- Cloud synchronization
- Test fixtures

---

## Action Executor

Executes the actions produced by the engine.

Examples include:

- Audio
- Haptic feedback
- Lighting
- Notifications
- Logging

The engine never executes actions directly.

---

## Persistence Provider

Stores persistent information when required.

Examples include:

- Configuration
- Logs
- Statistics

The engine does not know where data is stored.

---

# Platform Independence

GeoCore does not depend on:

- Operating systems
- Microcontrollers
- Communication protocols
- Device drivers
- Cloud services

Replacing any platform component must never require changes to the engine.

---

# Processing Flow

```
Platform

↓

Observations

↓

GeoCore Engine

↓

Actions

↓

Platform
```

The platform observes the world.

GeoCore decides.

The platform executes.

---

# Interface Rules

Every platform implementation must respect the following principles.

- Keep interfaces minimal.
- Never expose hardware details.
- Never bypass the engine.
- Remain deterministic.
- Support simulation whenever possible.

---

# Future Evolution

Additional interfaces may be introduced as new capabilities become necessary.

New interfaces must remain generic and applicable to every supported platform.

---

# Related Documents

- DR-003 – Architecture
- DR-004 – GeoCore Engine
- DR-005 – Domain Model