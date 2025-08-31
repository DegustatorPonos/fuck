#ifndef FUCK_ARRAY_H
#define FUCK_ARRAY_H

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

typedef struct{
    size_t Length;
    void **ptr;
} PtrArray;

// Makes a new array struct in stack and allocates 
// a memory for the array in the heap
PtrArray fck_array_init(size_t len);

// Frees the allocated memory and prevents futher array usage
void fck_array_deinit(PtrArray *base);

// Inserts value in the array. Returns the success status
bool fck_array_insert(PtrArray base, size_t address, void *value);

// Returns a pointer to the value from the array
void *fck_array_get(PtrArray base, size_t address);

#endif //FUCK_ARRAY_H
