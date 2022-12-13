//void initNeo(void **handle); //Initializes SPI interface and returns a handle to an opaque structure that you 
//can declare in your library. 
//setNeoRGB(void *handle, uint8_t r, uint8_t g, uint8_t b); //Turns on the neopixel with the provided r, g, b 
//(red, green, blue) color values. It takes the handle obtained by initNeo function.

#pragma once
#include <cstdint>

//typedef struct neopixel_inst_t* neopixel_t;
//void *handle;

void initNeo(void **handle);

void setNeoRGB(void *handle, uint8_t r,uint8_t g, uint8_t b);
