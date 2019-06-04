#pragma once
#include <stdint.h>

struct Location {
    uint_fast8_t x;
    uint_fast8_t y;
};

struct Direction {
    int_fast16_t dx;
    int_fast16_t dy;
};