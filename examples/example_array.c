#include "../src/arrays/array.h"
#include <stdint.h>
#include <stdio.h>

int main() {
    PtrArray a = fck_array_init(10);
    int val = 32;
    fck_array_insert(a, 2, &val);
    printf("Inserted value: %d\n", *(int*)fck_array_get(a, 2));
    fck_array_deinit(&a);
}

