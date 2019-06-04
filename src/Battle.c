#include "Battle.h"
#include "minmax.h"
#include "Item.h"
#include "Location.h"
#include "definitions.h"

void overwriteBattleState(struct BattleState *src, struct BattleState *dest){
    for(int i=0;i<MAX_FIGHTER_COUNT;i++){
        (*dest).fighters[i] = (*src).fighters[i];
    }
    for(int i=0;i<MAP_SIZE;i++){
        (*dest).terrain[i] = (*src).terrain[i];
    }
}

void tickBattle(struct Battle *battle){
    //swap curent and next
    struct BattleState *c = (*battle).current;
    (*battle).current=(*battle).next;
    (*battle).next=c;
    //overwrite next with current
    overwriteBattleState((*battle).current,(*battle).next);
}


void moveFighter(struct Battle * battle, int fighterIndex, struct Direction move){
    uint_fast8_t x = (*(*battle).next).fighters[fighterIndex].location.x;
    uint_fast8_t y = (*(*battle).next).fighters[fighterIndex].location.y;

    //trace line through terrain until unwalkable tile or edge is hit
    bool stopped = false;
    while(!stopped){
        //stopped = next line x,y == impassible or off map
    }
    
    (*(*battle).next).fighters[fighterIndex].location.x = x;
    (*(*battle).next).fighters[fighterIndex].location.y = y;
}

void applyItemEffect(struct Battle *battle, uint_fast8_t skills[SKILLS_MAX], struct Item item, struct Location location){

}

void useItemDirection(struct Battle * battle, int fighterIndex, EquipSlot slot, struct Direction direction){
    struct Location l = {
        .x = (*(*battle).next).fighters[fighterIndex].location.x,
        .y = (*(*battle).next).fighters[fighterIndex].location.y
    };
    struct Item item = (*(*battle).next).fighters[fighterIndex].character.inventory[(*(*battle).next).fighters[fighterIndex].character.equippedItems[(int) slot]];

    bool stopped = false;
    while(!stopped){
        applyItemEffect(battle, (*(*battle).next).fighters[fighterIndex].character.skills, item, l);
        //stopped = next line x,y == impassible or off map or fighter
    }

}
void useItemSelf(struct Battle * battle, int fighterIndex, EquipSlot slot);