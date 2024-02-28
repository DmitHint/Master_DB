#ifndef MASTER_LEVELS_H
#define MASTER_LEVELS_H

#include "libs.h"

int protect_level(FILE* ptr, int level);
int show_levels(FILE* ptr, int size);
int insert_levels_record(FILE* ptr, levels new_rec);
int delete_levels_record(FILE* ptr, levels rec);
int update_levels_record(FILE* ptr, levels old_rec, levels new_record);

#endif