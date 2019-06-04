#pragma once
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include "EquipSlot.h"
#include "definitions.h"

#define INVENTORY_MAX 32

struct Character {
    char *name;

    uint_fast8_t skills[SKILLS_MAX];
    uint_fast8_t skillInTraining;
    time_t skillTrainingCompletesAt;

    struct Item *inventory[INVENTORY_MAX];
    uint_fast8_t equippedItems[equipslot_COUNT];
    bool isSkilledCache[equipslot_COUNT];
    time_t nextEnchantmentTime;

    uint_fast32_t money;
};