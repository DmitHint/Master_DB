#include "../include/shared.h"

void clean_buffer() {
    int c;
    while ((c = getchar()) != '\0' && c != EOF && c != '\n') {
    }
}

int read_choice(int low, int high) {
    int num;
    int status = 0;
    while (!status) {
        if (scanf("%d", &num) != 1) {
            printf("n/a\n");
            clean_buffer();
        } else if ((num > high) || (num < low)) {
            printf("n/a\n");
        } else
            status = 1;
    }
    return num;
}

void output_size_menu() { printf("Insert the number of records or write \"-1\" to output all of them: "); }

void insert_levels_menu() { printf("Insert fields for record in \"level\" (int, int, int): "); }
void update_levels_old_menu() {
    printf("Insert fields of the updating record in \"level\" (int, int, int): ");
}
void update_levels_new_menu() { printf("Insert new values (int, int, int): "); }
void delete_levels_menu() { printf("Insert values of record to delete (int, int, int): "); }

void update_modules_old_menu() { printf("Insert id to update in \"module\": "); }
void delete_modules_menu() { printf("Insert id to delete in \"module\": "); }

int modules_control(int operation) {
    int status = 1;
    int id;
    int level, cell;
    modules rec;
    FILE* ptr = fopen(modules_fpath, "rb+");
    switch (operation) {
        case 1:
            output_size_menu();
            int size;
            if (scanf("%d", &size) != 0) {
                show_modules(ptr, size);
            } else {
                clean_buffer();
            }
            break;
        case 2:
            rec = input_module();
            status = insert_modules_record(ptr, rec);
            break;
        case 3:
            update_modules_old_menu();
            if (scanf("%d", &id) != 0) {
                rec = input_module();
                status = update_modules_record(ptr, id, rec);
            } else {
                printf("n/a\n");
                clean_buffer();
            }
            break;
        case 4:
            delete_modules_menu();
            scanf("%d", &id);
            status = delete_modules_record(ptr, id);
            break;
        case 5:
            status = show_active_modules(ptr);
            break;
        case 6:
            printf("Module id for moving: ");
            if (scanf("%d", &id) != 1) {
                clean_buffer();
                printf("n/a\n");
                break;
            }
            printf("Insert new level: ");
            if (scanf("%d", &level) != 1) {
                printf("n/a\n");
                clean_buffer();
                break;
            }
            printf("Insert new cell: ");
            if (scanf("%d", &cell) != 1) {
                printf("n/a\n");
                clean_buffer();
                break;
            }
            status = move_to_level_cell(ptr, id, level, cell);
            break;
    }
    fclose(ptr);
    return status;
}

int levels_control(int operation) {
    int status = 1;
    int id;
    int level;
    levels rec;
    levels new_rec;
    FILE* ptr = fopen(levels_fpath, "rb+");
    switch (operation) {
        case 1:
            output_size_menu();
            int size;
            if (scanf("%d", &size) != 0) {
                show_levels(ptr, size);
            } else {
                clean_buffer();
            }
            break;
        case 2:
            insert_levels_menu();
            if (scanf("%d%d%d", &rec.level, &rec.cells_num, &rec.pr_flag) == 3) {
                insert_levels_record(ptr, rec);
            }
            break;
        case 3:
            update_levels_old_menu();
            if (scanf("%d%d%d", &rec.level, &rec.cells_num, &rec.pr_flag) == 3) {
                update_levels_new_menu();
                if (scanf("%d%d%d", &new_rec.level, &new_rec.cells_num, &new_rec.pr_flag) == 3) {
                    update_levels_record(ptr, rec, new_rec);
                }
            }
            break;
        case 4:
            delete_levels_menu();
            if (scanf("%d%d%d", &rec.level, &rec.cells_num, &rec.pr_flag) == 3) {
                delete_levels_record(ptr, rec);
            }
            break;

        case 6:
            scanf("%d", &id);
            update_levels_new_menu();
            if (scanf("%d%d%d", &new_rec.level, &new_rec.cells_num, &new_rec.pr_flag) == 3) {
                update_levels_record(ptr, rec, new_rec);
            }
            break;
        case 7:
            scanf("%d", &level);
            protect_level(ptr, level);
            break;
    }
    fclose(ptr);
    return status;
}

int events_control(int operation) {
    int status = 1;
    FILE* ptr = fopen(events_fpath, "rb+");
    switch (operation) {
        case 1:
            output_size_menu();
            int size;
            if (scanf("%d", &size) != 0) {
                show_events(ptr, size);
            } else {
                clean_buffer();
            }
            break;
    }

    fclose(ptr);
    return status;
}