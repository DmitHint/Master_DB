#ifndef SHARED_H
#define SHARED_H

#include "master_levels.h"
#include "master_modules.h"
#include "master_status_events.h"

int read_choice(int low, int high);
int modules_control(int operation);
int levels_control(int operation);
int events_control(int operation);

void clean_buffer();

void output_size_menu();
void insert_levels_menu();
void update_levels_old_menu();
void update_levels_new_menu();
void delete_levels_menu();
void update_modules_old_menu();
void delete_modules_menu();

#endif