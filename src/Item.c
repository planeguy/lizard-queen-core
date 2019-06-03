#include "Item.h"
#include <stdint.h>
#include <stdbool.h>
#include "definitions.h"

bool isSkilled(uint_fast8_t skills[SKILLS_MAX], uint_fast8_t minimum[SKILLS_MAX]){
    for(uint_fast8_t i=0;i<SKILLS_MAX;i++){
        if(skills[i]<minimum[i]) return false;
    }
    return true;
}