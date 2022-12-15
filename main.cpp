#include "mbed.h"
#include <cstdint>
#include "neopixel.h"

//SPI spi(D11, D12, D13); // mosi, miso, sclk
//DigitalOut cs(D10);




void *handle;

int main()
{
    printf("deneme1: %p\n", handle);//0x0

    initNeo(&handle);//handle = ...
    printf("deneme1: %p\n", handle);//ffffxa3bf

    while (true) {
        setNeoRGB(handle, 0x00, 0xFF, 0x00);
    }
     
}

