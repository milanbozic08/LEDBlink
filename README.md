*Milan Bozic		April 2022*



Project documentation





|TASK|Blink|
| :-: | :-: |
|PROJECT|Test|
|HARDWARE|Nucleo L152RE|
|<p>BRIEF DESCRIPTION :</p><p></p><p>Firmware for STM32L152RET6 on a board Nucleo L152RE for control led blink on pin PA5 with push button on pin PC13 with software debounce via non blocking function. (PWM + Interrupt)</p>|


# Contents
[1.	Task	3](#_Toc101549426)

[2.	Idea	3](#_Toc101549427)

[3.	Block diagram	3](#_Toc101549428)

[4.	Implementation	3](#_Toc101549429)




1. # Task

The board has one button and one LED. Program a code that makes the LED flash (500 ms on/500 ms off, then 500 ms on again) while the button is pressed. Debounce the button via software.

1. # Idea

Prepare PWM with frequency of 1Hz with duty cycle of 50%. Prepare timer in interrupt mode for debounce. Turn on interrupt for rising and falling edge for button pin. 

When user push button then callback function start debounce timer and in timer callback check state of button and turn on or turn off pwm for led blink. 

1. # Block diagram

![](Documentation/Block_diagram/blockdiagram.png)

*Figure 1 : Block diagram of the task*
1. # Implementation

Implementation : Core/Src/interrupts.c

Setup : Core/Inc/configuration/config.h
