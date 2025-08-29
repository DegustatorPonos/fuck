#include "../src/arrays/array.h"
#include <stdint.h>
#include <stdio.h>

int main() {
    Array a = fucking_array_init(sizeof(int32_t), 10);
    int val = 32;
    fucking_array_insert(a, 1, &val);
    printf("Inserted value: %d\n", *(int*)fucking_array_get(a, 1));
    fucking_array_deinit(&a);
}
