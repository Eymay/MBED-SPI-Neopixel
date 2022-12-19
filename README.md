# MBED-SPI-Neopixel

A library that can be used to control Adafruit Neopixel LED's with SPI of MBED OS. 

Colours are not accurate as the SPI functionality of MBED contains an inherent delay to SPI write function.

To use the library create a handle to interact with it:

`void *handle`

Call initNeo function with the handle's address:

`initNeo(&handle)`

Then you can set any colour to the LED, code below sets red, green and blue in order:
`setNeoRGB(handle, 0xFF, 0x00, 0x00)`
`setNeoRGB(handle, 0x00, 0xFF, 0x00)`
`setNeoRGB(handle, 0x00, 0x00, 0xFF)`

Or to set white:
`setNeoRGB(handle, 0xFF, 0xFF, 0xFF)`
