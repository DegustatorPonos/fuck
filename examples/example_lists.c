#include "../src/arrays/lists.h"
#include <stdio.h>

typedef struct {
    int Id;
} Data;

int main() {
    PtrList list = fck_list_init(2);
    Data data0 = {.Id = 0};
    Data data1 = {.Id = 1};
    Data data2 = {.Id = 29};
    fck_list_append(&list, &data0);
    fck_list_append(&list, &data1);
    fck_list_append(&list, &data2);
    printf("List len: %lu | cap = %lu\n", list.Length, list.Capacity);

    for(int i = 0; i < list.Length; i++) {
        void *test = fck_list_get(&list, i);
        if (test == NULL) {
            printf("Null flag!\n");
            break;
        }
        printf("Object id: %d\n", ((Data*)fck_list_get(&list, i))->Id);
    }
    fck_list_deinit(&list);
}
