# MRWaterTank
Designs for 3D printing parts and building a microcontroller to motorize a 1D Med-Tec/CNMC water tank for use in an MR-Linac

### Overview

A major challenge in the commissioning of MR-guided Linear Accelerators is that the magnetic field environment causes many standard pieces of medical physics equipment to either be unsafe or non-functional.  Water tanks are a crucial tool for commissioning linear accelerators, and using a motorized water tank can result in significant time savings when acquiring dosimetry data such as percent depth dose (PDD) curves.  Although commercial MR-conditional motorized water tanks are becoming available, they are expensive and not yet widely available, so standard practice is to use a manual "crank" water tank to take point-by-point depth dose curves, with the physicist needing to enter the accelerator vault between measurements to manually adjust the position of the radiation detector (this is particularly challenging, as the physicist needs to crawl into the magnet bore to access the water tank).

This project develops an MR-conditional motorized attachment and controller for an existing 1D manual water tank in our department.  The project uses an ultrasonic motor and low-cost "DIY" electronics components as well as a 3D-printed motor mount/gear assembly.  Our department had an existing manual 1D water tank that was sitting unused, so total cost of components was ~$1500 (most of which is the ultrasonic motor), which compares favorably to the $100k+ for commercial options.

### Bill of Materials
* Manual Water Tank (e.g. MedTec/CNMC WP-3040 or similar water tank that will be safe to use in an MR environment)
* Shinsei USR30-E3N Ultrasonic Motor w/ 500 PPR Encoder
* Shinsei D6060E Motor Driver
* WEMOS D1 Mini ESP8266 Microcontroller (or other Arduino-compatiple microcontroller)
* Electronics Components
  * Breadboard or PCB board
  * DB-9 connector/breakout board
  * Logic level shifter board (if using 3.3V microcontroller with 5V LCD)
  * LCD1602 with I2C module (for displaying status/location)
  * Misc. buttons/switches (for controlling motor)
  * 24V PSU for D606E

### Instructions
1. **Acquire project components**
1. **Print the motor holder and gears**

   This assembly consists of a motor holder as well as two gears.  One gear slides on to the motor shaft and the second is designed to fit over the existing crank handle on the water tank (so that the motor holder can quickly be removed and the tank can be operated manually if needed).  The gears use a herringbone design to eliminate the need for additional securing hardware.  The motor holder is designed to be secured to the water tank by loosening the attachment screws that are part of the manual tank encoder, and sliding it underneath.  There is a slot that is designed to fith the USR30-E3N (we additionally used a piece of silk tape to ensure the motor stays secure).
   
   *NOTE: The design of the holder/handle gear may need to be modified depending on the specific water tank.* 
   
   These components were 3D printed on an Ultimaker S5 using Tough PLA

1. **Assemble motor driver circuit**


