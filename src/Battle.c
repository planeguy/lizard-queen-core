#include "Battle.h"
#include "minmax.h"
#include "Item.h"
#include "Location.h"

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