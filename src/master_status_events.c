#include "../include/master_status_events.h"

int show_events(FILE* ptr, int size) {
    int is_error = 0;
    events rec;
    if (ptr == NULL) {
        is_error = 1;
    } else {
        printf("========= EVENTS =========\n");
        fread(&rec, sizeof(events), 1, ptr);
        int i = 0;
        while (!feof(ptr) && (i < size || size == -1)) {
            printf("%d %d %d %s %s\n", rec.event_id, rec.module_id, rec.status, rec.date, rec.time);
            fread(&rec, sizeof(events), 1, ptr);
            i++;
        }
    }
    return is_error;
}