#ifndef MASTER_MODULES_H
#define MASTER_MODULES_H

#include "libs.h"

int show_modules(FILE* ptr, int size);
int insert_modules_record(FILE* ptr, modules rec);
int delete_modules_record(FILE* ptr, int id);
int update_modules_record(FILE* ptr, int old_id, modules new_record);
int show_active_modules(FILE* ptr);
int move_to_level_cell(FILE* ptr, int id, int level, int cell);
modules input_module();
void get_name(char* name);

#endif