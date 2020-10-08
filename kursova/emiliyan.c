#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.c"

int main() {
    left *left_head  = NULL;
    right *right_head = NULL;
    char *file_name = "info.bin";
    int max;
    int min;

    get_info(file_name);
    create_lists(file_name, &left_head, &right_head);
    traverse(&left_head, &right_head);
    equalize(&left_head, &right_head, file_name, &max, &min);
    traverse(&left_head, &right_head);
    kpp(&left_head, &right_head, &max, &min);

    printf("ALL DONE\nALL VEHICLES PASSED THROUGH\n");

    return 0;
}
