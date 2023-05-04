# Lora-based environmental monitor
* intended for monitoring collection items in musea. Other applications are possible but the unit is currently designed for indoor use only
* monitors temperature, relative humidity, VOC gasses, barometric pressure, light intensity and others
	- BME680 and TSL25911 sensors are built in, other can be added through I2C or UART
* runs on a single cell LiFePO4 battery. Battery-charger from USB-C port included
* Wio-E5 LoRa module from www.seeedstudio.com. This contains an STM32WLE processor combined with Semtech SX126X radio. The firmware runs directly on the STM32. More info on this Wio-E5 :  https://www.seeedstudio.com/LoRa-E5-Wireless-Module-p-4745.html
* 128 KByte of onboard EEPROM allows to buffer sensor-readings when network is unavailable.
* ePaper display allows to identify the device, and read status from the display, while still being ultra low power.


The related firmware for this device can be found in https://github.com/Strooom/MuMo-v2-Node-SW

![PCB Render Top view](https://github.com/Strooom/MuMo-V2-Node-PCB/blob/main/PCB%203D%20view%20Top.PNG "PCB Render Top view")

![PCB Backside Functional Blocks](https://github.com/Strooom/MuMo-V2-Node-PCB/blob/main/MuMo%20PCB%20Functional%20Blocks-Back.png "PCB Backside Functional Blocks")

![PCB Frontside Functional Blocks](https://github.com/Strooom/MuMo-V2-Node-PCB/blob/main/MuMo%20PCB%20Functional%20Blocks-Front.png "PCB Frontside Functional Blocks")


More info can be found in the Wiki : 
https://github.com/Strooom/MuMo-V2-Node-PCB/wiki
