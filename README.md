# Smart Automatic Clothesline

An Arduino-based system that automatically moves your laundry under cover when rain is detected, and returns it outside when the weather clears.

## Features

- **Rain Detection**: Uses analog and digital rain sensor outputs
- **Automatic Protection**: Servo moves clothes to protected position (90°) when rain detected
- **Auto-Return**: Returns clothes outside (0°) when rain stops
- **Real-time Monitoring**: Serial output shows sensor values and system status
- **Adjustable Sensitivity**: Threshold can be tuned for your environment

## Hardware Required

- Arduino (Uno/Nano/Mega)
- Rain sensor module (FC-37 or similar)
- Servo motor (standard 180°)
- Power supply (for servo if needed)
- Jumper wires
- Small mechanism to attach clothesline to servo

## Wiring Diagram

```

Rain Sensor Module:
VCC → 5V
GND → GND
A0 (Analog) → A0
D0 (Digital) → D2

Servo Motor:
Signal (Orange) → Pin 9
VCC (Red) → 5V
GND (Brown) → GND

```

## How It Works

### Simple Version (Basic Control)

- Reads analog value from rain sensor
- If value > 500 → rain detected → servo to 90°
- Else → no rain → servo to 0°
- Prints values to Serial Monitor

### Advanced Version (Full System)

- Reads both analog and digital sensor outputs
- Rain detection uses either: digital LOW OR analog > threshold
- Prevents repeated movements with state tracking
- 1-second delay between checks
- Clear serial status messages

## Installation

1. Upload code to Arduino
2. Open Serial Monitor (9600 baud)
3. Test with water drops on sensor
4. Adjust threshold if needed
5. Attach clothesline mechanism to servo

## Calibration

### Find Your Threshold

```

Dry sensor reading: ~200-300
Wet sensor reading: ~700-1023

```

Set `RAIN_THRESHOLD` midway between dry/wet values.

## Customization

- **Threshold**: Change `RAIN_THRESHOLD` value
- **Positions**: Modify `POSITION_OUTSIDE` and `POSITION_PROTECTED` angles
- **Check Interval**: Adjust `delay()` in main loop
- **Movement Speed**: Change delay after servo writes

## Serial Output Example

```

Rain Detection Clothes Protector Started!
Clothes are OUTSIDE
Analog: 245 | Digital: 1 | Status: No rain. Clothes already outside
Analog: 756 | Digital: 0 | Status: RAIN DETECTED! Moving clothes INSIDE...
Analog: 812 | Digital: 0 | Status: RAIN DETECTED! Clothes already protected
Analog: 267 | Digital: 1 | Status: No rain. Moving clothes OUTSIDE...

```

## Troubleshooting

| Problem              | Solution                                   |
| -------------------- | ------------------------------------------ |
| No rain detection    | Check sensor connections; adjust threshold |
| False triggers       | Increase threshold; clean sensor board     |
| Servo not moving     | Check power; verify pin 9 connection       |
| Jerky movement       | Add capacitor across servo power           |
| Sensor too sensitive | Use digital output instead of analog       |

## Applications

- Automatic clothesline
- Greenhouse window control
- Car window closer
- Patio umbrella automation
- Plant watering protection

## License

MIT - Free for learning and modification
