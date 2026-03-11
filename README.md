## Embedded OLED Dice

Simple embedded project for STM32 that simulates a dice roll on a SSD1306 OLED display.



Pressing the button triggers a random dice roll and the result is displayed visually on OLED display.



The project demonstrates basic embedded concepts such as GPIO interrupts, I2C communication,

and simple graphics rendering.



## Demo



![Dice demo](https://github.com/nikodemwyborny/embedded-oled-dice/blob/main/docs/demo.GIF)



## Project Structure

Firmware is organized into separate modules:



* button – GPIO interrupt and debounce
* display – OLED rendering
* random - pseudo-random numbers generator (PRNG)
* app – application logic
* SSD1306 – display driver





## Features



* OLED graphics rendering
* Dice visualization
* Button interrupt (EXTI)
* Software debounce
* Modular firmware structure





## How it works



1. Button press triggers an external interrupt (EXTI)
2. The interrupt sets a button event flag
3. AppLogic generates a random dice value (1-6) using a custom PRNG
4. Dice is rendered visually on the OLED display





## Tools



* STM32CubeIDE
* STM32CubeMX
* SSD1306 OLED driver
* C language





## Hardware



MCU: STM32 NUCLEO-F446RE

Display: SSD1306 OLED (128x64)

Communication: I2C

Input: User button (GPIO interrupt)





### STM32CubeMX configuration

![CubeMX pinout](https://github.com/nikodemwyborny/embedded-oled-dice/blob/main/docs/cubeMX-pinout.png)





### Hardware schematic

![Schematic](https://github.com/nikodemwyborny/embedded-oled-dice/blob/main/docs/schematic.png)





## Third-party libraries



This project uses an SSD1306 OLED driver based on open-source code by:



* Piotr Duba
* Adafruit SSD1306 / Adafruit GFX



The driver was adapted for STM32 HAL and simplified for this project.



Original libraries are distributed under the MIT/BSD license.

