# DC Motor On-Off Control

## Description
Switches a small low-voltage DC motor through a proper driver stage. The motor is never connected directly to an ATmega328P GPIO pin.

## Hardware
- Arduino Uno R3 (ATmega328P)
- Small low-voltage DC motor
- Low-voltage transistor or motor-driver module
- Flyback protection if required by the driver
- External motor supply
- Jumper wires

## Code
See [main.c](main.c).

## Circuit
![Breadboard](images/breadboard.jpg)
