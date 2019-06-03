#pragma once
#include <stdint.h>
#include "Character.h"
#include "Location.h"
#define MAP_SIZE 24*24

struct Fighter {
    struct Character character;
    uint_fast8_t hp = 100;
    uint_fast8_t mp = 100;
    struct Location location;
};

struct Battle {
    struct Fighter fighters[2];
    uint_fast8_t terrain[MAP_SIZE];
};