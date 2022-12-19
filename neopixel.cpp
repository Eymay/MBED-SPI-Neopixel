#include <cstdint>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "neopixel.h"


struct neopixel_inst_t{
    SPI *spi;
};

inline void write_one(SPI *spi){
    spi->write(0xFC);
    return;
}
inline void write_zero(SPI *spi){
    spi->write(0xE0);
    return;
}
inline bool last_bit(uint8_t data){
    return (data & 0x01); 
}
void initNeo(void **handle){
    struct neopixel_inst_t *temp = (struct neopixel_inst_t *)calloc(1, sizeof(struct neopixel_inst_t));
    SPI *spi = new SPI(D11, D12, D13);
    spi->set_dma_usage(DMA_USAGE_ALWAYS);
    spi->format(8, 1);
    spi->frequency(10000000);


    temp->spi = spi;
    *handle = (void *)temp;


}
void setNeoRGB(void *handle, uint8_t r,uint8_t g, uint8_t b){

    SPI *spi_temp = ((struct neopixel_inst_t*)(handle))->spi;
    for (int i = 0; i < 8; i++) {

            if(last_bit(g)){
                write_one(spi_temp);
            }else {
                write_zero(spi_temp);
            }
            g = g >> 1;
    }
    for (int i = 0; i < 8; i++) {

            if(last_bit(r)){
                write_one(spi_temp);
            }else {
                write_zero(spi_temp);
            }
            r = r >> 1;
    }
    for (int i = 0; i < 8; i++) {

            if(last_bit(b)){
                write_one(spi_temp);
            }else {
                write_zero(spi_temp);
            }
            b = b >> 1;
    }
            wait_us(300);
}


