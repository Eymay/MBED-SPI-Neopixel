
#pragma once
#include <cstdint>
#include "mbed.h"

void initNeo(void **handle);

void setNeoRGB(void *handle, uint8_t r,uint8_t g, uint8_t b);

