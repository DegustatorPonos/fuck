#ifndef FUCK_ARRAY_H
#define FUCK_ARRAY_H

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

typedef struct{
    void *ptr;
    size_t Length;
    size_t data_type;
} Array;

// Makes a new array struct in stack and allocates 
// a memory for the array in the heap
Array fucking_array_init(size_t type, size_t len);

// Frees the allocated memory and prevents futher array usage
void fucking_array_deinit(Array *base);

// Inserts value in the array. Returns the success status
bool fucking_array_insert(Array base, size_t address, void *value);

// Returns a pointer to the value from the array
void *fucking_array_get(Array base, size_t address);

#endif //FUCK_ARRAY_IMPL_H
