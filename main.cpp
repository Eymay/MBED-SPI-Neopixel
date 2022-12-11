#include "mbed.h"

SPI spi(D11, D12, D13); // mosi, miso, sclk
// main() runs in its own thread in the OS
int main()
{
    spi.format(8, 3);
    spi.frequency(1000000);

    spi.write(0x8F);

    //while (true) {}
     
}

