#include "Item.h"
#include <stdint.h>
#include "definitions.h"

bool isSkilled(uint_fast8_t skills[SKILLS_MAX], uint_fast8_t minimum[SKILLS_MAX]){
    for(uint_fast8_t i=0;i<SKILLS_MAX;i++){
        if(skills[i]<minimum[i]) return false;
    }
    return true;
}

struct *Item loadItem(
    char* name,
    uint_fast8_t skillsMinimum[SKILLS_MAX],
    uint_fast8_t skilledUseEffects[effecttype_COUNT],
    uint_fast8_t unskilledUseEffect[effecttype_COUNT],
    bool canEquipTo[equipslot_COUNT]
);

struct *Item newEmptyItem(){
    return loadItem(
        "",
        new uint_fast8_t[SKILLS_MAX]{},
        new uint_fast8_t[effecttype_COUNT]{},
        new uint_fast8_t[effecttype_COUNT]{},
        new bool canEquipTo[equipslot_COUNT]{true}
    );
}