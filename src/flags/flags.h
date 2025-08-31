#ifndef FUCK_FLAGS_H
#define FUCK_FLAGS_H

#include "../arrays/array.h"

typedef struct {
    char *Flag;
    PtrArray *Values;
} Flag;

// Returns an array of Flag structs pointers
PtrArray fck_parse_flags(int argc, char **argv);

// Frees all the flags structs
void fck_forget_flags(PtrArray *flags);

bool fck_isFlag(char *entry);
// Returns the next flag position in the 
int fck_get_next_flag_entry(int start, int argc, char **argv);

#endif
