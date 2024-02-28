#ifndef LIBS_H
#define LIBS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define levels_fpath "./database/master_levels.db"
#define modules_fpath "./database/master_modules.db"
#define events_fpath "./database/master_status_events.db"
#define temp_fpath "./database/temp.db"

typedef struct {
    int id;
    char name[30];
    int level;
    int cell;
    int flag;
} modules;

typedef struct {
    int level;
    int cells_num;
    int pr_flag;
} levels;

typedef struct {
    int event_id;
    int module_id;
    int status;
    char date[11];
    char time[9];
} events;

#endif