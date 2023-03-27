# TestPlan

## Naked PCB
OK 1. check for short between GND, VBAT, 5V
2. check for continuity between
	- CP2102N and STM32 : Rx, Tx
	- USB 5V and MCP73123
	- STM32 and eInk connector : MOSI, SPICLK, CS, BUSY, D/C, e.a.

## Soldering
1. USB-C connector, 2 resistors, esd : test 5V
2. MCP73123 + passives : test battery charging
3. MCU + passives + BGR24G256 : test SWD, I2C, GPIO
4. eInk power supply + connector + passives : test display


## Assembled PCB - Front Only
### HW only tests
1. check for short between GND, VBAT
2. check if USB Serial is detected by PC
3. check if battery is being charged

### HW tests requiring firmware
4. send serial data
5. check if STM32 detects USB power
6. check if STM32 detects batteryVoltage
7. check if I2C devices are detected : 
	Grove BME680 = 0x76,
	Grove TSL2591 = 0x29,
	BR24G256 = 0x50
8. perform write / read test to BR24G256
9. detect RESET button being pressed
10. test serial connection over USB

## Assembled PCB - Front & Back
1. check if I2C devices are detected : onboard BME680 = 0x76, onboard TSL2591 = 0x29



## Assembly Log
1. the 4u7 caps are easily thombstoning.. How will they behave in reflow oven ?
2. SMA connector - check it's straight before soldering all grounds
3. first time flashing the SW : SWD is not enabled, so you need to keep reset pressed, then connect the ST-Link, then release reset. Then erase the BB bits into AA, then flash with firmware having SWD enabled.
4. 10K ? Is correct according to datasheet from mouser

## ToDo
1. Terminals on second battery
2. Ground pin on scope probe
3. Check continuity of all display signals
4. Fix display reset signal
5. check is wakeUp is possible from USB power on current pin, or if PA0 would be a better pin
6. check if SPI chip select can move to PB9
7. check if PB14 is available for BUSY input
