#include "array.h"
#include <string.h>
#include <stdlib.h>

Array fucking_array_init(size_t type, size_t len) {
    Array outp = {
        .Length = len,
        .data_type = type,
        .ptr = malloc(type * len)
    };
    return outp;
}

void fucking_array_deinit(Array *base) {
    free(base->ptr);
    base->Length = 0;
}

bool fucking_array_insert(Array base, size_t address, void *value) {
    if(base.Length <= address) {
        return false;
    }
    memcpy(base.ptr + base.data_type * address, value, base.data_type);
    return true;
}

void *fucking_array_get(Array base, size_t address) {
    if(base.Length <= address) {
        return NULL;
    }
    return base.ptr + base.data_type * address;
}
