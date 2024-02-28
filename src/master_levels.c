#include "../include/master_levels.h"

int show_levels(FILE *ptr, int size) {
    int status = 1;
    levels rec;
    if (ptr == NULL) {
        status = 0;
    } else {
        printf("========= LEVELS =========\n");
        fread(&rec, sizeof(levels), 1, ptr);
        int i = 0;
        while (!feof(ptr) && (i < size || size == -1)) {
            printf("%d %d %d\n", rec.level, rec.cells_num, rec.pr_flag);
            fread(&rec, sizeof(levels), 1, ptr);
            i++;
        }
    }
    return status;
}

int insert_levels_record(FILE *ptr, levels rec) {
    int status = 1;
    if (ptr == NULL) {
        status = 0;
    } else {
        fseek(ptr, 0, SEEK_END);
        fwrite(&rec, sizeof(levels), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return status;
}

int protect_level(FILE *ptr, int level) {
    levels temp;
    int status = 1;
    if (ptr == NULL) {
        status = 0;
    } else {
        int found = 0;
        fseek(ptr, 0, SEEK_SET);
        while (fread(&temp, sizeof(levels), 1, ptr) && !found) {
            if (temp.level == level) {
                fseek(ptr, -(long int) sizeof(levels), SEEK_CUR);
                temp.pr_flag = 20;
                fwrite(&temp, sizeof(levels), 1, ptr);
                found = 1;
            }
        }
        if (!found) {
            printf("NO SUCH LEVEL\n");
        }
        fclose(ptr);
    }

    return status;
}

int delete_levels_record(FILE *ptr, levels rec) {
    int status = 1;
    if (ptr == NULL) {
        status = 0;
    } else {
        levels temp;
        fseek(ptr, 0, SEEK_SET);
        FILE *tmp_file = fopen(temp_fpath, "wb");
        fseek(tmp_file, 0, SEEK_SET);
        while (fread(&temp, sizeof(levels), 1, ptr)) {
            if (!(temp.cells_num == rec.cells_num && temp.level == rec.level &&
                  temp.pr_flag == rec.pr_flag)) {
                fwrite(&temp, sizeof(levels), 1, tmp_file);
            }
        }
        fclose(tmp_file);
        fclose(ptr);
    }

    return status;
}

int update_levels_record(FILE *ptr, levels old_rec, levels new_record) {
    int status = 1;
    if (ptr == NULL) {
        status = 0;
    } else {
        fseek(ptr, 0, SEEK_SET);
        levels temp;
        int found = 0;
        while (fread(&temp, sizeof(levels), 1, ptr) && !found) {
            if (temp.cells_num == old_rec.cells_num && temp.level == old_rec.level &&
                temp.pr_flag == old_rec.pr_flag) {
                fseek(ptr, -sizeof(levels), SEEK_CUR);
                fwrite(&new_record, sizeof(levels), 1, ptr);
                found = 1;
            }
        }
        if (!found) printf("NOTHING TO UPDATE\n");
        fseek(ptr, 0, SEEK_SET);
    }
    return status;
}