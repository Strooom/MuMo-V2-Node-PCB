# Hardware Tests Before Flashing Firmware

So you've assembled a MuMo v2 PCB and now you want to test it to verify if the hardware was manufactured without errors.
Here is a step-by-step plan to do that:

1. Check for shorts between GND and 5V : use a multimeter to measure resistance between testpads for GND and 5V. You should NOT measure a low value (< 100 ohm). If not, check the soldering of the USB connector.
2. Check for shorts between GND and 3.3V : use a multimeter to measure resistance between testpads for GND and 3.3V. You should NOT measure a low value (< 100 ohm).

If there are no shorts in this part of the power supply, it should be safe to power a board via the USB connector.

3. Connect USB cable and plug the other side into a power usb port. Check for 5V and 3.6V presence on the test-pads

If this is OK, it should be safe to connect a battery

4. Unplug USB, and connect a battery. Double check the polarity of the battery, as the board is not designed to protect against wrong battery polarity !
5. Check presence of battery voltage on GND / 3V3 testpads
6. Additionally you can chech the current consumption from the battery. It should be around a few mA (this is the power consumption of the STM32WLE. The Wio-E5 module is factory programmed with an AT-Modem application)
6. ReConnect USB. Now you should measure the charging current of the LiFePO4 battery, which is around 150 mA

7. Now we are ready to flash some HW test software into the STM32WLE: 
    7.1 Connect the ST-Link programmer to the debug port. Either solder headers on the PCB (for prototyping) or use POGO pins (for volume production)
    7.2 The programmer needs the following 4 signals : GND, 3.3V, SWCLK, SWD.  SWO-Trace is provided on the connector (pin 5) but is not required for programming, only required for debug output during SW development. Check the correct order of the signals between the programmer and the MuMo board
    7.3 The Wio-E5 module gets a firmware programmed (an AT-Modem application). For some (mystery / license / ??) reason, after getting this firmware the STM32WLE is protected for reading out the firmware using the so-called option bits. In order to overwrite the already programmed application with our test-formware, you need to proceed as follows :
        7.4 : start the STM32CubeProgrammer
        7.5 : Press the RESET button on the MuMo board and while this button is pressed, click on Connect in the STM32CubeProgrammer. Now the programmer should find the bootloader of the SMT32WLE
        7.6 : Now remove the protection set by the OPTION bits : TBC
        7.7 : Now we can program our own application : select the .bin file, and program it.

# Hardware Tests from the Firmware

Now the firmware can perform a test-program :
1. The output of the tests will be sent to a serial-port over the USB, so on your PC, open a Serial Monitor program, set it to 115200 Baud. Reset the MuMo (reset button) and monitor the output to the serial port. You should see a welcome message and a prompt from the Command Line Interface (CLI)

2. Following commands are related to testing the board :
    2.1 : VER (VERsion) : will show information of the software version
    2.2 : TEST : run a complete hardware test displaying the results in the serial monitor

    This includes following tests :
    * Measure battery voltage
    * Detect all devices connected to I2C : show the addresses where devices are found :
    * Read / Write test of the EEPROM
    * Display test
    * UART loopback test when a jumper cable is connected between GROVE UART