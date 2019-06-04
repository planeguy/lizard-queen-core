#pragma once
#include <stdint.h>
#include "Character.h"
#include "Location.h"
#define MAP_WIDTH 20
#define MAP_HEIGHT 20
#define MAP_SIZE 400
#define MAX_FIGHTER_COUNT 2

struct Fighter {
    struct Character character;
    uint_fast8_t hp;
    uint_fast8_t mp;
    struct Location location;
};

struct BattleState {
    struct Fighter fighters[MAX_FIGHTER_COUNT];
    uint_fast8_t terrain[MAP_SIZE];
};

struct Battle
{
    struct BattleState *current;
    struct BattleState *next;
};

void tickBattle(struct Battle * battle);

void moveFighter(struct Battle * battle, int fighterIndex, struct Direction move);
void useItemDirection(struct Battle * battle, int figherIndex, EquipSlot slot, struct Direction direction);
void useItemSelf(struct Battle * battle, int fighterIndex, EquipSlot slot);