#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct l_Vehicles {
    int val;
    struct l_Vehicles *next;
}left;

typedef struct r_Vehicles {
    int val;
    struct r_Vehicles *next;
}right;

void get_info(char *file_name);
void create_lists(char *file_name, left **left_head, right **right_head);
void traverse(left **left_head, right **right_head);
void equalize(left **left_head, right **right_head, char *file_name, int *max, int *min);
void kpp(left **left_head, right **right_head, int *max, int *min);

#endif // FUNCTIONS
