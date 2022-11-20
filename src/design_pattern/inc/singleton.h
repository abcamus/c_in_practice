#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct {
    unsigned rest_time;
    void (*take_rest)(unsigned time);
} HouseKeeper;

/* singleton interfaces */
HouseKeeper *single_house_keeper();
void delete_single_house();

#endif