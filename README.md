# PICado LCD Button Demo

This project demonstrates the use of **HD44780 16x2 character LCD** with an **ATmega2560** (PICado Mega) and buttons connected to PORTA. Each button triggers a different action on the LCD.

* T0–T7 buttons are connected to **PA0–PA7**.
* Internal pull-ups are enabled.
* The LCD runs in **4-bit mode** using the **HD44780 library**.

---

## Features

| Button | Action                          |
| ------ | ------------------------------- |
| T0     | Prints `"Hello World!"`         |
| T1     | Prints `"23"`                   |
| T2     | Prints `"3.141"`                |
| T3     | Displays a custom symbol        |
| T4     | Shifts the display to the right |
| T7     | Clears the display              |

The project supports **special characters** like `\n`, `\t`, `\r`, `\b`, and `\f` for string printing.

---

## Hardware Connections

### LCD

| LCD Pin | AVR Port |
| ------- | -------- |
| RS      | PL0      |
| RW      | PL1      |
| EN      | PL2      |
| BL      | PL3      |
| D4      | PL4      |
| D5      | PL5      |
| D6      | PL6      |
| D7      | PL7      |

### Buttons

| Button | AVR Pin |
| ------ | ------- |
| T0     | PA0     |
| T1     | PA1     |
| T2     | PA2     |
| T3     | PA3     |
| T4     | PA4     |
| T7     | PA7     |

> Other pins can be reassigned in the `main.c` file. Pull-ups are enabled internally.

---

## Project Setup

Before building the project, a small configuration step is required.

### 1. Install AVRdude

Download AVRdude from:

[https://github.com/ml3rc/01_SchrittMot/tree/main/readme/AVRdude](https://github.com/ml3rc/01_SchrittMot/tree/main/readme/AVRdude)

Place it in:

```
C:\Program Files (x86)\Atmel\Studio\7.0\tools\
```

Adjust the folder if your Microchip Studio version differs.

---

### 2. Configure the Programming Tool

Open the project properties in Microchip Studio:

```
Project → PICado LCD Button Demo Properties
```

Navigate to:

```
Tool → Custom programming tool → Command
```

Update the following in the command:

* Repository path of AVRdude
* COM port of your development board

---

## Building and Flashing

Once the setup is complete, the firmware can be built and flashed directly from Microchip Studio.

Use:

```
Start Without Debugging (Green start button with a hole in the middle)
```

This will:

1. Compile the firmware
2. Upload it to the ATmega2560
3. Start execution immediately