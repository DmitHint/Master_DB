#include "../include/shared.h"

void show_main_menu() {
    printf(
        "===============================================================\n"
        "Please choose one operation:\n"
        "1. SELECT\n"
        "2. INSERT\n"
        "3. UPDATE\n"
        "4. DELETE\n"
        "5. Get all active additional modules\n"
        "6. Move module by id to specified memory level and cell\n"
        "7. Set protection flag of the specified memory level\n"
        "===============================================================\n");
}

void show_db_menu() {
    printf(
        "=============================\n"
        "Please choose a table :\n"
        "1. Modules\n"
        "2. Levels\n"
        "3. Status events\n"
        "=============================\n");
}

int main() {
    int status = 1;
    int choice;
    int flag = 1;
    while (flag) {
        show_main_menu();
        int operation = read_choice(-1, 9);
        switch (operation) {
            case 0:
                printf("n/a\n");
                break;
            case 1:
                show_db_menu();
                choice = read_choice(1, 3);
                if (choice == 1) status = modules_control(operation);
                if (choice == 2) status = levels_control(operation);
                if (choice == 3) status = events_control(operation);
                break;
            case 2:
                show_db_menu();
                choice = read_choice(1, 3);
                if (choice == 1) status = modules_control(operation);
                if (choice == 2) status = levels_control(operation);
                if (choice == 3) printf("error\n");
                break;
            case 3:
                show_db_menu();
                choice = read_choice(1, 3);
                if (choice == 1) status = modules_control(operation);
                if (choice == 2) status = levels_control(operation);
                if (choice == 3) printf("error\n");
                break;
            case 4:
                show_db_menu();
                choice = read_choice(1, 3);
                if (choice == 1) {
                    status = modules_control(operation);
                    if (status) {
                        remove(modules_fpath);
                        rename(temp_fpath, modules_fpath);
                    }
                }
                if (choice == 2) {
                    status = levels_control(operation);
                    if (status) {
                        remove(levels_fpath);
                        rename(temp_fpath, levels_fpath);
                    }
                }
                if (choice == 3) {
                    status = events_control(operation);
                    if (status) {
                        remove(events_fpath);
                        rename(temp_fpath, events_fpath);
                    }
                }
                break;

            case 5:
                status = modules_control(operation);
                break;

            case 6:
                status = modules_control(operation);
                break;

            case 7:
                status = levels_control(operation);
                break;

            case -1:
                flag = 0;
                break;
        }
        if (!status) {
            flag = 0;
            printf("error\n");
        }
    }
    return 0;
}