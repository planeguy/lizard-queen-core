#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "EquipSlot.h"
#include "EffectType.h"
#include "definitions.h"

struct Item {
    char *name;

    uint_fast8_t skillsMinimum[SKILLS_MAX];
    uint_fast16_t skilledUseEffects[effecttype_COUNT];
    uint_fast16_t unskilledUseEffects[effecttype_COUNT];

    bool canEquipTo[equipslot_COUNT];
};

bool isSkilled(uint_fast8_t skills[SKILLS_MAX], uint_fast8_t minimum[SKILLS_MAX]);