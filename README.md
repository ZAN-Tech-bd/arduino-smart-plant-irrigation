# Smart Automatic Plant Watering System

An Arduino-powered "robotic gardener" that checks whether your plant is thirsty and waters it automatically. A 16x2 LCD screen shows the soil moisture level and pump status in real time.

## Table of Contents

- [How It Works](#how-it-works)
- [Parts List](#parts-list)
- [Wiring Guide](#wiring-guide)
- [Getting Started](#getting-started)
- [Configuration](#configuration)
- [Troubleshooting](#troubleshooting)
- [Safety Tips](#safety-tips)
- [License](#license)

## How It Works

1. The soil moisture sensor reads how wet the soil is.
2. The Arduino converts the reading into a percentage and shows it on the LCD.
3. If the soil is too dry, the relay turns **ON** and the pump waters the plant for 5 seconds.
4. If the soil is wet enough, the pump stays **OFF**.
5. The system checks again every 2 seconds.

## Parts List

| Component | Purpose |
| --- | --- |
| Arduino Uno | The "brain" of the system |
| YL-69 Soil Moisture Sensor | Measures water in the soil |
| 5V Relay Module | Safely switches the pump on and off |
| Mini Submersible Water Pump | Pumps water from a cup into the plant pot |
| 16x2 I2C LCD Display | Shows moisture level and pump status |
| 18650 Batteries + Holder | Powers the pump |
| Jumper Wires | Connect everything together |

## Wiring Guide

> **Note:** Ask a teacher or parent for help with the battery and water pump wiring.

![Smart Automatic Plant Watering System pictorial wiring diagram](Smart%20Automatic%20Plant%20Watering%20System%20pictorial%20wiring%20diagram.png)

### LCD Display (I2C)

| LCD Pin | Arduino Pin |
| --- | --- |
| GND | GND |
| VCC | 5V |
| SDA | A4 |
| SCL | A5 |

### Soil Moisture Sensor (YL-69)

| Sensor Pin | Arduino Pin |
| --- | --- |
| VCC | 5V |
| GND | GND |
| A0 | A0 |

### Relay Module

| Relay Pin | Arduino Pin |
| --- | --- |
| VCC | 5V |
| GND | GND |
| IN (Signal) | D8 |

### Water Pump and Batteries

| From | To |
| --- | --- |
| Battery negative (-, black) | Pump negative (-, black) |
| Battery positive (+, red) | Relay COM |
| Pump positive (+, red) | Relay NO (Normally Open) |

When the relay turns on, it connects COM and NO, completing the circuit and running the pump.

## Getting Started

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the LCD library:
   - Go to **Sketch > Include Library > Manage Libraries**.
   - Search for **LiquidCrystal I2C** by Frank de Brabander and click **Install**.
3. Open [arduino-smart-plant-irrigation.ino](arduino-smart-plant-irrigation.ino) in the Arduino IDE.
4. Connect the Arduino Uno to your computer with the USB cable.
5. Select **Tools > Board > Arduino Uno**, choose the correct port, and click **Upload**.
6. Test it:
   - Sensor in **dry** soil: the screen shows `Pump: ON`.
   - Sensor in **wet** soil: the screen shows `Pump: OFF`.

## Configuration

These values can be changed in the sketch:

| Setting | Default | Description |
| --- | --- | --- |
| `dryThreshold` | `700` | Raw sensor value above which the soil counts as dry |
| LCD I2C address | `0x27` | Change to `0x3F` if the screen stays blank |
| Pump run time | `5000` ms | How long the pump runs each time |
| Check interval | `2000` ms | Delay between moisture readings |

## Troubleshooting

| Problem | Solution |
| --- | --- |
| LCD is blank or shows only blocks | Turn the contrast screw on the back of the LCD until text appears |
| LCD is still blank | Change the I2C address in the code from `0x27` to `0x3F` |
| Pump never turns on | Check the relay wiring (COM/NO) and make sure the batteries are charged |
| Moisture reading looks wrong | Check the sensor wiring to A0 and adjust `dryThreshold` |

## Safety Tips

- Keep the Arduino and batteries away from water. Only the pump and the sensor prongs should touch water or wet soil.
- Always disconnect power before changing any wiring.

## License

Copyright (c) ZAN Tech. All rights reserved.
