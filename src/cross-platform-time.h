#pragma once
#include <stdint.h>
#define MINUTES_PER_DAY 1440

struct Time {
    uint_fast16_t year;
    uint_fast16_t dayOfYear;
    uint_fast16_t minuteOfDay;
};

struct Time addDays(uint_fast32_t days, struct Time t);
struct Time addMinutes(uint_fast32_t minutes, struct Time t);

// ******************************************
// just going to define these in here for now
// ******************************************
int daysThisYear(uint_fast16_t year){
    //is a leap year
    if((year % 4 == 0) && (year % 400 == 0 || !(year % 100 == 0))){
        return 366;
    }
    return 365;
}

struct Time yearAddHelper(uint_fast32_t days, uint_fast16_t year){
    if(days==0 || days<daysThisYear(year)){
        struct Time n = {
            .year = year,
            .dayOfYear = days,
            .minuteOfDay = 0
        };
        return n;
    }
    return yearAddHelper(days-daysThisYear(year), year+1);
}

struct Time addDays(uint_fast32_t days, struct Time t){
    int dpy = daysThisYear(t.year);
    struct Time n = yearAddHelper(days, t.year);
    n.minuteOfDay = t.minuteOfDay;
    return n;
}
struct Time addMinutes(uint_fast32_t minutes, struct Time t){
    if (minutes+t.minuteOfDay >= MINUTES_PER_DAY){
        uint_fast32_t minutesLeft = (minutes+t.minuteOfDay)-MINUTES_PER_DAY;
        struct Time n = addDays(minutesLeft/MINUTES_PER_DAY, t);
        n.minuteOfDay = minutesLeft % MINUTES_PER_DAY;
        return n;
    }
    t.minuteOfDay+=minutes;
    return t;
};