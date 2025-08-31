#include "flags.h"
#include <assert.h>
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FLAG_NAME "Input";

Flag *parseFlag(char **argc, int start, int end);

PtrArray fck_parse_flags(int argc, char **argv) {
    assert(argc >= 1 && "The amount of args should be equal or greater than one");
    PtrArray a = fck_array_init(argc);
    size_t array_index = 0;
    int i = 1;
    while(i < argc) {
        int next_flag = fck_get_next_flag_entry(i, argc, argv);
        if(next_flag >= argc) {
            next_flag = argc;
        }
        Flag *flag = parseFlag(argv, i, next_flag);
        if(!fck_array_insert(a, array_index, flag)) {
            printf("[ERROR] Failed to form a flag struct: the insertion of %s in the outp array\n", flag->Flag);
        };
        array_index++;
        i = next_flag;
    }
    // Losing some allocated memory here but it's like at most 100 bytes soo WHO CARES
    a.Length = array_index;
    return a;
}

bool fck_isFlag(char *entry) {
    return *entry == '-';
}

Flag *parseFlag(char **argc, int start, int end) {
    assert(start != end && "Invalid flag parsing range");
    Flag *flag = malloc(sizeof(Flag));
    // Checking if the first element is the flag
    if(fck_isFlag(argc[start])) {
        flag->Flag = argc[start];
        start++;
    } else {
        flag->Flag = DEFAULT_FLAG_NAME;
    }
    // printf("[INFO] Creating a flag array with %d values\n", end - start);
    PtrArray vals = fck_array_init(end - start);
    for(int i = start; i < end; i++) {
        if(!fck_array_insert(vals, i-start, argc[i])) {
            printf("[ERROR] Failed to form a flag struct: the insertion of %s to index %d failed\n", argc[i], i-start);
            break;
        }
    }
    flag->Values = malloc(sizeof(PtrArray));
    *flag->Values = vals;
    return flag;
}


int fck_get_next_flag_entry(int start, int argc, char **argv) {
    if(start == argc) {
        return argc + 1;
    }
    for(int i = start + 1; i < argc; i++) {
        if(fck_isFlag(argv[i])) {
            return i;
        }
    }
    return argc + 1;
}

void fck_forget_flags(PtrArray *flags) {
    for(int i = 0; i < flags->Length; i++) {
        Flag *data = fck_array_get(*flags, i);
        if(data == NULL) 
            break;
        free(data);
    }
    fck_array_deinit(flags);
}
