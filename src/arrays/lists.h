#ifndef FUCK_LIST_H
#define FUCK_LIST_H

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

typedef struct{
    size_t Length;
    size_t Capacity;
    void **ptr;
} PtrList;

// Makes a new list struct in stack and allocates 
// a memory for the list in the heap
PtrList fck_list_init(size_t init_cap);

// Frees the allocated memory and prevents futher list usage
void fck_list_deinit(PtrList *base);

// Inserts value in the list. Returns the success status
bool fck_list_insert(PtrList *base, size_t address, void *value);

// Returns a pointer to the value from the list
void *fck_list_get(PtrList *base, size_t address);

// Inserts value in the list. Returns the success status
bool fck_list_append(PtrList *base, void *value);

#endif //FUCK_LIST_H
