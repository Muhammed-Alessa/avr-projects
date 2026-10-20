# avr-projects

Bare-metal AVR projects from my second-year college study, rebuilt for the **Arduino Uno R3 / ATmega328P**.


The important point is that the **Arduino Uno is only being used as an ATmega328P development board**. The projects do **not** use Arduino functions such as `digitalWrite()`, `pinMode()`, or `Serial.begin()`. They use AVR registers directly with **AVR-GCC**, just like normal AVR development.

## Project Structure

Each project uses the same simple layout:

```text
Project XX - Project Name/
├── main.c
├── README.md
└── images/
    └── .gitkeep
```


## Board Mapping

Useful Arduino Uno / ATmega328P mappings:

| Arduino pin | AVR pin |
|---|---|
| D0 | PD0 / RXD |
| D1 | PD1 / TXD |
| D2 | PD2 / INT0 |
| D3 | PD3 / INT1 |
| D8 | PB0 |
| D9 | PB1 |
| D10 | PB2 |
| D11 | PB3 / MOSI |
| D12 | PB4 / MISO |
| D13 | PB5 / SCK / built-in LED |
| A0 | PC0 / ADC0 |
| A1 | PC1 / ADC1 |
| A4 | PC4 / SDA |
| A5 | PC5 / SCL |

## Toolchain

Target:

```text
MCU: ATmega328P
Clock: 16 MHz
Compiler: AVR-GCC
Board: Arduino Uno R3
```

Example compilation:

```bash
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os main.c -o main.elf
avr-objcopy -O ihex -R .eeprom main.elf main.hex
```

Upload through the Uno bootloader by replacing `COM3` with the correct serial port:

```bash
avrdude -c arduino -p atmega328p -P COM3 -b 115200 -D -U flash:w:main.hex:i
```

Projects containing additional `.c` files must compile those files too. For example, the UART library project can be built with:

```bash
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os main.c uart.c -o main.elf
avr-objcopy -O ihex -R .eeprom main.elf main.hex
```

## Projects

- `Project 01 - Blinking the On-Board LED`
- `Project 02 - Four Blinking LEDs`
- `Project 03 - Using PORTB and PORTD as Outputs`
- `Project 04 - 7-Segment LED Counter`
- `Project 05 - Digital Input with Pushbutton`
- `Project 06 - Pushbutton with Internal Pull-Up`
- `Project 07 - Three Buttons and Three LEDs`
- `Project 08 - Pushbutton Debouncing`
- `Project 09 - DC Motor On-Off Control`
- `Project 10 - DC Motor Direction Control`
- `Project 11 - External Interrupt INT0`
- `Project 12 - External Interrupts INT0 and INT1`
- `Project 13 - UART Transmitter`
- `Project 14 - UART Receiver`
- `Project 15 - UART Transmit and Receive`
- `Project 16 - UART String Transmission`
- `Project 17 - Reusable UART Driver Library`
- `Project 18 - ADC Potentiometer Reading`
- `Project 19 - FreeRTOS - Three LED Tasks`
