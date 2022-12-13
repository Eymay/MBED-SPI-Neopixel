#include "neopixel.h"
#include <cstdint>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"

//SPI spi(D11, D12, D13); // mosi, miso, sclk
//DigitalOut cs(D10);


/*
struct neopixel_inst{
        SPI spi(uint8_t mosi, uint8_t miso, uint8_t sclk );
        DigitalOut cs(uint8_t cs);
};
*/
struct neopixel_inst_t{
    SPI *spi;
    DigitalOut *cs;
};

/*void neopixel_inst(){
    spi = spi(D11, D12, D13);
    cs =  cs(D10);
}
*/
void initNeo(void **handle){
    void *temp = calloc(1, sizeof(struct neopixel_inst_t));
    SPI spi(D11, D12, D13);
    DigitalOut cs(D10);
    temp->spi = &spi;
    temp->cs = &cs;
    handle = temp;
}

void setNeoRGB(void *neopixel_t, uint8_t r,uint8_t g, uint8_t b);

