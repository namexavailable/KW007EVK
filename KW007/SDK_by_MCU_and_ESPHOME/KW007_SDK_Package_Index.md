# KW007 SDK Package Index

## Keywave KW007 5.8 GHz Doppler Radar Sensor

This index helps developers choose the correct KW007 software package for their platform.

All current packages are aligned with **KW007 SDK v1.3** and the **KW007 Programming Guide v2.1**.

---

## Available Packages

| Package | Recommended For | Language / Framework | Notes |
|---|---|---|---|
| **KW007_Arduino_v1.3** | Arduino Uno, Nano, Mega, SAMD, nRF52 and compatible Arduino boards | Arduino / C++ | General Arduino library package with installable library structure and Arduino examples |
| **KW007_ESP32_v1.3** | ESP32, ESP32-C3, ESP32-S3 and other ESP32-family boards using Arduino core | Arduino / C++ | ESP32-focused package with configurable I2C pins and ESP32 usage notes |
| **KW007_ESPHome_ESP32C3_v1.3** | Home Assistant users and ESPHome developers using ESP32-C3 | ESPHome / YAML | Ready-to-use Home Assistant integration with Motion, Approaching, Leaving, Direction, RSSI, range control, GPO delay and update-rate control |
| **KW007_Pico2W_v1.3** | Raspberry Pi Pico / Pico 2 W using Arduino core | Arduino / C++ | Pico-focused Arduino package using configurable GP pins for I2C |
| **KW007_MicroPython_v1.3.0** | Raspberry Pi Pico, Pico 2 W and other boards running MicroPython | MicroPython | Uses `machine.I2C`; suitable for rapid prototyping and embedded scripting |
| **KW007_Python_RaspberryPi_v1.3.0** | Raspberry Pi 4 / 5 and Linux SBCs | Python 3 | Uses Linux I2C via `smbus2`; suitable for Raspberry Pi OS and Linux applications |
| **KW007_SDK_STM_v1.3** | STM32 MCU projects using STM32CubeIDE / STM32 HAL | C / STM32 HAL | Includes STM32 HAL integration instructions and the portable KW007 C SDK |

---

## Which Package Should I Use?

### Arduino boards

Use:

```text
KW007_Arduino_v1.3
```

Recommended for Arduino Uno, Nano, Mega, SAMD, nRF52 and other boards using the Arduino framework.

---

### ESP32 / ESP32-C3 / ESP32-S3

Use:

```text
KW007_ESP32_v1.3
```

Recommended when developing directly with the Arduino framework on ESP32-family devices.

If the target system is Home Assistant / ESPHome, use the ESPHome package instead.

---

### Home Assistant / ESPHome

Use:

```text
KW007_ESPHome_ESP32C3_v1.3
```

This package provides a ready-to-use KW007 integration for ESP32-C3 and Home Assistant.

It includes:

- Motion
- Approaching
- Leaving
- Direction
- RSSI
- Adjustable Detection Range
- Adjustable GPO Delay
- Adjustable Detection Update Rate

It can be used directly or modified for custom Home Assistant applications and automations.

---

### Raspberry Pi Pico / Pico 2 W with Arduino

Use:

```text
KW007_Pico2W_v1.3
```

This package is intended for Pico / Pico 2 W users working in Arduino IDE.

---

### Raspberry Pi Pico / Pico 2 W with MicroPython

Use:

```text
KW007_MicroPython_v1.3.0
```

This is the preferred package for users working with Thonny or MicroPython.

---

### Raspberry Pi 4 / Raspberry Pi 5 / Linux SBC

Use:

```text
KW007_Python_RaspberryPi_v1.3.0
```

This package uses Python 3 and the Linux I2C interface through `smbus2`.

---

### STM32

Use:

```text
KW007_SDK_STM_v1.3
```

This package is intended for STM32CubeIDE / STM32 HAL projects.

---

## Common KW007 Interface Information

The current packages follow the same KW007 v1.3 configuration model.

### I2C Address

```text
7-bit address: 0x19
Bus byte:
  Write: 0x32
  Read:  0x33
```

Use the address form expected by the target platform.

For example:

```text
Arduino Wire / Linux / ESP-IDF / MicroPython: 0x19
STM32 HAL:                                  0x32
```

---

## I2C / Software-Control Mode

Before power-up, connect:

```text
KW007 Range1 -> GND
```

For software-control mode, Range1 must be connected directly to GND.

Do not use a series resistor in this mode.

---

## Power

Use either:

```text
3.3 V
```

or:

```text
5 V
```

Never use both at the same time.

3.3 V is recommended for most MCU development boards.

---

## Detection Range Presets

All current packages use the same v1.3 detection-range presets:

| Level | Typical Range | Threshold | Sensitivity | Enhanced |
|---:|---:|---:|---:|:---:|
| 1 | ~20 cm | 80 | 2 | Off |
| 2 | ~50 cm | 80 | 2 | Off |
| 3 | ~1 m | 80 | 2 | Off |
| 4 | ~3 m | 80 | 4 | Off |
| 5 | ~5 m | 90 | 8 | Off |
| 6 | ~7 m | 64 | 8 | Off |
| 7 | ~10 m | 32 | 8 | Off |
| 8 | ~12 m | 32 | 8 | On |

Detection range is controlled using a combination of:

- amplifier gain
- magnitude threshold
- sensitivity
- enhanced mode

Use the shortest range that reliably covers the intended application.

---

## Motion Direction

KW007 provides independent motion-direction flags:

```text
Approaching
Leaving
```

A generic motion state can be derived as:

```text
Motion = Approaching OR Leaving
```

This indicates motion and should not be treated as a dedicated stationary-presence or occupancy flag.

---

## RSSI

KW007 provides an RSSI value from:

```text
0 to 255
```

RSSI is useful for setup, tuning and signal evaluation.

It is not a distance measurement.

For normal operation, applications do not need to read RSSI continuously.

---

## Documentation

Use these documents together with the platform packages:

```text
KW007_Programming_Guide_v2.1.pdf
KW007_SDK_v1.3.html
```

The Programming Guide provides:

- hardware setup
- I2C interface
- register map
- initialization flow
- gain / threshold / sensitivity tuning
- GPO delay
- recommended range settings

The SDK HTML reference provides:

- API reference
- register-level interface
- HAL interface
- platform architecture
- function descriptions

---

## Recommended Starting Configuration

For first evaluation:

```text
Detection Range:   Level 4 (~3 m)
Supply:            3.3 V
I2C:               100 kHz or 400 kHz
Range1:            Directly to GND
Polling:           Approximately 8 Hz or faster host polling
```

Change one parameter at a time during evaluation.

---

## Current Release Set

```text
KW007_Arduino_v1.3
KW007_ESP32_v1.3
KW007_ESPHome_ESP32C3_v1.3
KW007_MicroPython_v1.3.0
KW007_Pico2W_v1.3
KW007_Python_RaspberryPi_v1.3.0
KW007_SDK_STM_v1.3

KW007_Programming_Guide_v2.1.pdf
KW007_SDK_v1.3.html
```

---

## License

Unless otherwise stated in a package, Keywave-provided SDK source and integration files are licensed under the Apache License, Version 2.0.

See the `LICENSE` file included with each package.

---

Copyright 2026 Keywave Technology.
