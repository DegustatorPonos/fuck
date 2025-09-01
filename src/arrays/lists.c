#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool fck_list_expand(PtrList *base, size_t margin);

// Makes a new list struct in stack and allocates 
// a memory for the list in the heap
PtrList fck_list_init(size_t init_cap) {
    printf("test 2\n");
    int cap = init_cap == 0 ? init_cap : 1;
    PtrList list = {
        .Capacity = cap,
        .Length = 0,
        .ptr = malloc(sizeof(void*) * cap)
    };
    return list;
}

// Frees the allocated memory and prevents futher list usage
void fck_list_deinit(PtrList *base) {
    free(base->ptr);
}

// Inserts value in the list. Returns the success status
bool fck_list_insert(PtrList *base, size_t address, void *value) {
    if(base->Length <= address) {
        return false;
    }
    base->ptr[address] = value;
    return true;
}

// Returns a pointer to the value from the list
void *fck_list_get(PtrList *base, size_t address) {
    printf("test\n");
    if(base->Length <= address) {
        return NULL;
    }
    return base->ptr[address];
}

// Inserts value in the list. Returns the success status
bool fck_list_append(PtrList *base, void *value) {
    if(base->Length >= base->Capacity && !fck_list_expand(base, base->Capacity)) {
        return false;
    }
    base->ptr[base->Length] = value;
    base->Length++;
    return true;
}

bool fck_list_expand(PtrList *base, size_t amount) {
    printf("Reallocating!\n");
    size_t new_cap = base->Capacity += amount;
    void *newMem = malloc(sizeof(void*) * new_cap);
    if(newMem == NULL) {
        return false;
    }
    memcpy(base->ptr, newMem, sizeof(void *) * base->Capacity);
    free(base->ptr);
    base->Capacity = new_cap;
    base->ptr = newMem;
    return true;
}
