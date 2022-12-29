# Improvements MuMo V2 HW vs V1

1. has a USB-C connector (io. USB-micro) which is the new EU standard for charging devices
2. has a USB-UART chip (CN2102N) so the USB connection with any PC-host will stay alive. V1 loses the connection after going into low-power-sleep
3. has a built-in charger for LiFePO4 battery. The MCU is aware of external USB-power and can adjust its program flow on it.
4. has the 2 most common sensors (BME68x and TSL2591/TSL2561) built in, and still 2 Grove-I2C and 1 Grove-UART connector, for extending to additional sensors
5. runs the SW on the embedded STM32WLE5 MCU, reducing size, power and cost. V1 used an ATSAMD21 MCU which is currently out of stock.
6. has EEPROM on the PCB to store:
    - all network settings. V1 requires a unique firmware per device. V2 firmware will be standard and use unique settings from EEPROM
    - all data until confirmed by the cloud application
    - V1 stored settings in the MCU flash, but this flash has a limited number of erase/write cycles (10K io. 10M)
7. has a better antenna connector (SMA), resulting in better radio signal, lower power, more bandwidth, etc. Different antennas exist for this connector
8. has an ePaper display. This display will improve the human interaction with the device:
    - show the device's identity
    - show the battery level
    - show charging progress
    - show network connectivity
    - show any kind of alarms, measurement values, etc
9. can be programmed and debugger via SWD connector with standard ST-LINK - Programming via USB is also foreseen 


# Improvements Descoped for this iteration, candidates for a next iteration
* could use a PCB antenna. This would require to also add an RF switch.


# Removed from the design
* Real-time clock (RTC) : I did no longer see the benefits vs the built-in RTC in the STM32, given that we can regularly sync its clock from the LoRa network.