#include "../include/master_modules.h"

int show_modules(FILE* ptr, int size) {
    int status = 1;
    modules rec;
    if (ptr == NULL) {
        status = 0;
    } else {
        printf("========= MODULES =========\n");
        fread(&rec, sizeof(modules), 1, ptr);
        int i = 0;
        while (!feof(ptr) && (i < size || size == -1)) {
            printf("%d %s %d %d %d\n", rec.id, rec.name, rec.level, rec.cell, rec.flag);
            fread(&rec, sizeof(modules), 1, ptr);
            i++;
        }
    }
    return status;
}

int insert_modules_record(FILE* ptr, modules rec) {
    int status = 1;
    if (ptr == NULL) {
        status = 0;
    } else {
        fseek(ptr, 0, SEEK_END);
        fwrite(&rec, sizeof(modules), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return status;
}

int delete_modules_record(FILE* ptr, int id) {
    int status = 1;
    if (ptr == NULL) {
        status = 0;
    } else {
        modules temp;
        fseek(ptr, 0, SEEK_SET);
        FILE* tmp_file = fopen(temp_fpath, "wb");
        fseek(tmp_file, 0, SEEK_SET);
        while (fread(&temp, sizeof(modules), 1, ptr)) {
            if (!(temp.id == id)) {
                fwrite(&temp, sizeof(modules), 1, tmp_file);
            }
        }
        fclose(tmp_file);
        fclose(ptr);
    }

    return status;
}

int update_modules_record(FILE* ptr, int old_id, modules new_record) {
    int status = 1;
    if (ptr == NULL) {
        status = 0;
    } else {
        fseek(ptr, 0, SEEK_SET);
        modules temp;
        int found = 0;
        while (fread(&temp, sizeof(modules), 1, ptr) && !found) {
            if (temp.id == old_id) {
                fseek(ptr, -sizeof(modules), SEEK_CUR);
                fwrite(&new_record, sizeof(modules), 1, ptr);
                found = 1;
            }
        }
        if (!found) printf("NOTHING TO UPDATE\n");
        fseek(ptr, 0, SEEK_SET);
    }
    return status;
}

int move_to_level_cell(FILE* ptr, int id, int level, int cell) {
    modules temp;
    int status = 1;
    if (ptr == NULL) {
        status = 0;
    } else {
        int found = 0;
        fseek(ptr, 0, SEEK_SET);
        while (fread(&temp, sizeof(modules), 1, ptr) && !found) {
            if (temp.id == id) {
                fseek(ptr, -sizeof(modules), SEEK_CUR);
                temp.cell = cell;
                temp.level = level;
                fwrite(&temp, sizeof(modules), 1, ptr);
                found = 1;
            }
        }
        if (!found) {
            printf("NO SUCH MODULE\n");
        }
    }
    return status;
}

int show_active_modules(FILE* ptr) {
    int status = 1;
    modules rec;
    if (ptr == NULL) {
        status = 0;
    } else {
        printf("========= MODULES =========\n");
        fread(&rec, sizeof(modules), 1, ptr);
        int i = 0;
        int found = 0;
        while (!feof(ptr)) {
            if (rec.flag != 0) {
                printf("%d %s %d %d %d\n", rec.id, rec.name, rec.level, rec.cell, rec.flag);
                found = 1;
            }
            fread(&rec, sizeof(modules), 1, ptr);
            i++;
        }
        if (!found) {
            printf("NO ACTIVE FILES\n");
        }
    }
    return status;
}

void get_name(char* name) {
    int size = 0;
    char c = ' ';
    scanf("%c", &c);
    if (c == '\n') scanf("%c", &c);
    while ((c != '\n') && (size != 30)) {
        name[size++] = c;
        scanf("%c", &c);
    }
    if (size > 30)
        printf("n/a\n");
    else
        name[size] = '\0';
}

modules input_module() {
    printf("== Enter record ==\n");
    modules rec;
    printf("Enter id (int): ");
    while (1) {
        if (scanf("%d", &(rec.id)) != 1)
            printf("n/a\n");
        else
            break;
    }
    printf("Enter name (char[30]): ");
    get_name(rec.name);
    printf("Enter level (int): ");
    while (1) {
        if (scanf("%d", &(rec.level)) != 1)
            printf("n/a\n");
        else
            break;
    }
    printf("Enter cell (int): ");
    while (1) {
        if (scanf("%d", &(rec.cell)) != 1)
            printf("n/a\n");
        else
            break;
    }
    printf("Enter flag (int): ");
    while (1) {
        if (scanf("%d", &(rec.flag)) != 1)
            printf("n/a\n");
        else
            break;
    }
    return rec;
}
