#include <cstdint>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "neopixel.h"
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

/*
struct neopixel_inst_t{
    //uint8_t mosi;
    //uint8_t cs;
    void *spi;
    void *cs;
};
*/
/*void neopixel_inst(){
    spi = spi(D11, D12, D13);
    cs =  cs(D10);
}
*/

void write_one(SPI *spi, DigitalOut *cs){
    *cs = 0;
    spi->write(0xFC);
    *cs = 1;
    return;
}

void write_zero(SPI *spi, DigitalOut *cs){
    *cs = 0;
    spi->write(0xE0);
    *cs = 1;
    return;
}

bool last_bit(uint8_t data){
    return (data & 0x01); 
}

void initNeo(void **handle){
    //printf("deneme2.5\n");

    struct neopixel_inst_t *temp = (struct neopixel_inst_t *)calloc(1, sizeof(struct neopixel_inst_t));
    //handle = (struct neopixel_inst_t *) handle;
    SPI *spi = new SPI(D11, D12, D13);
    DigitalOut *cs = new DigitalOut(D10);
    //SPI spi(D11, D12, D13);
    spi->set_dma_usage(DMA_USAGE_ALWAYS);
    //spi.format(8, 3);
    spi->format(8, 1);
    spi->frequency(10000000);
    //spi->write(0xFF);
    //static DigitalOut cs(D10);

    temp->spi = spi;
    temp->cs = cs;
    *handle = (void *)temp;
    //printf("deneme3\n");
    //*handle = temp;
    //const char* a = ((struct neopixel_inst_t*)(*handle))->str;
    //printf("out: %s\n", a);

}
void setNeoRGB(void *handle, uint8_t r,uint8_t g, uint8_t b){
    //printf("setNeoRGB\n");
    //const char* a = ((struct neopixel_inst_t*)(handle))->str;
    //printf("out: %s\n", a);

    SPI *spi_temp = ((struct neopixel_inst_t*)(handle))->spi;
    DigitalOut *cs_temp = ((struct neopixel_inst_t*)(handle))->cs;
    //spi_temp->write(0xFF);
    for (int i = 0; i < 8; i++) {

            if(last_bit(g)){
                write_one(spi_temp, cs_temp);
            }else {
                write_zero(spi_temp, cs_temp);
            }
            g = g >> 1;
    }
    for (int i = 0; i < 8; i++) {

            if(last_bit(r)){
                write_one(spi_temp, cs_temp);
            }else {
                write_zero(spi_temp, cs_temp);
            }
            r = r >> 1;
    }
    for (int i = 0; i < 8; i++) {

            if(last_bit(b)){
                write_one(spi_temp, cs_temp);
            }else {
                write_zero(spi_temp, cs_temp);
            }
            b = b >> 1;
    }
            wait_us(300);
}


