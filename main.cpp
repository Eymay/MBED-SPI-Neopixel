#include "mbed.h"

SPI spi(D11, D12, D13); // mosi, miso, sclk
DigitalOut cs(D10);
int main()
{
    spi.set_dma_usage(DMA_USAGE_ALWAYS);
    //spi.format(8, 3);
    spi.format(8, 1);
    spi.frequency(10000000);

    //spi.write(0xAA);
    //spi.write(0xAA);

    while (true) {
        //wait_us(100000);
        cs = 0;
        spi.write(0xFC);
        //spi.write(0xE0);
        cs = 1;
        //cs = 0;
        //spi.write(0xFC);
        //spi.write(0xFC);
        //cs = 1;
        //wait_us(2);
        //spi.write(0xAE);
    }
     
}

void write_one(){
    cs = 0;
    spi.write(0xFC);
    cs = 1;
    return;
}

void write_zero(){
    cs = 0;
    spi.write(0xE0);
    cs = 1;
    return;
}

