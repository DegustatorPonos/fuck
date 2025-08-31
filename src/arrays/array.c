#include "array.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

PtrArray fck_array_init(size_t len) {
    PtrArray outp = {
        .Length = len,
        .ptr = malloc(sizeof(void*)* len)
    };
    return outp;
}

void fck_array_deinit(PtrArray *base) {
    free(base->ptr);
    base->Length = 0;
}

bool fck_array_insert(PtrArray base, size_t address, void *value) {
    if(base.Length <= address) {
        return false;
    }
    base.ptr[address] = value;
    return true;
}

void *fck_array_get(PtrArray base, size_t address) {
    if(base.Length <= address) {
        return NULL;
    }
    return base.ptr[address];
}
