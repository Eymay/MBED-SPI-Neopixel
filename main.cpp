#include "mbed.h"
#include <cstdint>

class neopixel{
    SPI spi;
    DigitalOut cs;

    public:
    initNeo()

}

SPI spi(D11, D12, D13); // mosi, miso, sclk
DigitalOut cs(D10);


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

bool last_bit(uint32_t data){
    return (data & 0x00000001); 
}

void *handle;

int main()
{
    spi.set_dma_usage(DMA_USAGE_ALWAYS);
    //spi.format(8, 3);
    spi.format(8, 1);
    spi.frequency(10000000);

    //spi.write(0xAA);
    //spi.write(0xAA);

    initNeo(&handle);

    while (true) {
    uint32_t data = 0x00FF0000;
        //wait_us(100000);
            for (int i = 0; i < 24; i++) {

            if(last_bit(data)){
                write_one();
            }else {
                write_zero();
            }
            data = data >> 1;
            }
            wait_us(300);
        //cs = 0;
        //spi.write(0xFC);
        //spi.write(0xE0);
        //cs = 1;
        //cs = 0;
        //spi.write(0xFC);
        //spi.write(0xFC);
        //cs = 1;
        //wait_us(2);
        //spi.write(0xAE);

    }
     
}

