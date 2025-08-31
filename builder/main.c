#include "../src/flags/flags.h"
#include <stdio.h>

int main(int argc, char **argv) {
    Array flags = fck_parse_flags(argc, argv);
    for(int i = 0; i < flags.Length; i++) {
        Flag *flag = (Flag*)fck_array_get(flags, i);
        if(flag == NULL || flag->Flag == NULL) {
            printf("The flag name is null\n");
            break;
        }
        if(flag->Values == NULL) {
            printf("The flag values is null\n");
            continue;
        }
        printf("Flag name: %s | params: %lu\n", flag->Flag, flag->Values->Length);
        for(int j = 0; j < flag->Values->Length; j++) {
            printf("  Param: %s\n", (char*)fck_array_get(*(Array*)flag->Values, j));
        }
    }
    fck_array_deinit(&flags);
}
