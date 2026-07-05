Created:
2026-06-27

Last Updated:
2026-06-27

# DR-000 – Origin

| Field | Value |
|-------|-------|
| Version | 0.1 |
| Status | Approved |
| Created | 2026-06-27 |
| Last Updated | 2026-06-27 |
| Authors | Zang, ChatGPT |


---

# Why GeoCore Exists

GeoCore was not created to build a new dog collar.

It was created because an existing solution had reached its limits.

The starting point was a PetSafe wireless containment system. Although reliable, it relied on aging technology: a fixed radio transmitter, a circular virtual fence and disposable batteries inside the collar.

Meanwhile, the rest of the house had evolved.

Home Assistant had become the central automation platform.
ESP32 devices, Zigbee sensors and local automations were replacing proprietary systems.

The dog collar remained the only isolated device.

This raised a simple question.

**Why should a modern connected home rely on a twenty-year-old virtual fence?**

From that question, several others naturally followed.

Why is the fence always a circle?

Why can't it follow the exact shape of the property?

Why does it require a dedicated base station?

Why can't it integrate with Home Assistant?

Why are the algorithms hidden inside proprietary firmware?

Why is there no fully open-source alternative?

After researching the existing market, it became clear that commercial products had significantly improved GPS accuracy and user experience, but they remained closed ecosystems.

Some required subscriptions.

Some relied on cloud services.

None offered a fully open architecture allowing owners to understand, modify and improve the system.

GeoCore was born from this observation.

Its goal is not simply to replace an existing collar.

Its goal is to create an open, local-first and modular platform capable of making reliable geofencing decisions for animals.

The first application will be a virtual fence for dogs.

Nothing prevents future applications from using the same engine for other types of mobile devices.

The project follows one simple philosophy:

> The collar must remain autonomous.
>
> Everything else is optional.

GeoCore is designed around this principle.

The collar must continue to protect the animal even if:

* Internet is unavailable.
* Home Assistant is offline.
* Wi-Fi is disconnected.
* The owner's phone is turned off.

Configuration is external.

Decision making always remains inside the collar.

GeoCore is not intended to replace commercial products. Its purpose is to explore what an open, transparent and community-driven geofencing platform can become.

This document records the original motivation of the project and should remain stable throughout its lifetime.


Related Documents

DR-001 - Vision

DR-012 - Manifesto