#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void get_info(char *file_name) {
    int right_side;
    int left_side;

    printf("Right side number of vehicles: ");
    scanf("%d", &right_side);
    printf("Left side number of vehicles: ");
    scanf("%d", &left_side);

    FILE *fp = fopen(file_name, "wb");
    fwrite(&left_side, sizeof(int), 1, fp);
    fwrite(&right_side, sizeof(int), 1, fp);
    fclose(fp);
}

void create_lists(char *file_name, left **left_head, right **right_head) {
    left *left_temp   = *left_head;
    right *right_temp = *right_head;
    FILE *fp = fopen(file_name, "rb");

    int left_number;
    int right_number;
    fread(&left_number, sizeof(int), 1, fp);
    fread(&right_number, sizeof(int), 1, fp);

    //left side LIST
    for (int i = 1; i <= left_number; i++) {
        left *new_node = (left*) malloc(sizeof(left));
        new_node->val  = i;
        new_node->next = NULL;

        if (left_temp == NULL) {
            left_temp = new_node;
            *left_head = left_temp;
        }
        else {
            while (left_temp->next != NULL) {
                left_temp = left_temp->next;
            }
            left_temp->next = new_node;
        }
    }
    //right side LIST
    for (int i = 1; i <= right_number; i++) {
        right *new_node = (right*) malloc(sizeof(right));
        new_node->val  = i;
        new_node->next = NULL;

        if (right_temp == NULL) {
            right_temp = new_node;
            *right_head = right_temp;
        }
        else {
            while (right_temp->next != NULL) {
                right_temp = right_temp->next;
            }
            right_temp->next = new_node;
        }
    }
    fclose(fp);
}

void traverse(left **left_head, right **right_head) {
    left *left_temp = *left_head;
    right *right_temp = *right_head;

    printf("========right list=========\n");
    while (right_temp != NULL) {
        printf("%d\n", right_temp->val);
        right_temp = right_temp->next;
    }
    printf("===========================\n");

    printf("\n=======left list=========\n");
    while (left_temp != NULL) {
        printf("%d\n", left_temp->val);
        left_temp = left_temp->next;
    }
    printf("===========================\n\n");
}

void equalize(left **left_head, right **right_head, char *file_name, int *max, int *min) {
    left *left_temp = *left_head;
    right *right_temp = *right_head;
    right *right_prev;
    left *left_prev;

    FILE *fp = fopen(file_name, "rb");

    int left_number;
    int right_number;
    fread(&left_number, sizeof(int), 1, fp);
    fread(&right_number, sizeof(int), 1, fp);

    fclose(fp);

    if (left_number > right_number) {
        *max = left_number;
        *min = right_number;
    }
    else {
        *min = left_number;
        *max = right_number;
    }

    //how to free a certain number of vehicles...
    while ((*max - *min) > 5) {
        if (left_number == *max) {//left side is bigger
            //free 20 units from left side
            for (int i = 0; i < 20; i++) {
                left_temp = *left_head;
                while (left_temp->next != NULL) {
                    left_prev = left_temp;
                    left_temp = left_temp->next;
                }
                left_prev->next = NULL;
                free(left_temp);
            }
            *max-=20;
            //free 10 units from right side
            for (int i = 0; i < 10; i++) {
                right_temp = *right_head;
                while (right_temp->next != NULL) {
                    right_prev = right_temp;
                    right_temp = right_temp->next;
                }
                right_prev->next = NULL;
                free(right_temp);
            }
            *min-=10;
        }
        else {//else the right side is bigger
            //free 20 units from right side
            for (int i = 0; i < 20; i++) {
                right_temp = *right_head;
                while (right_temp->next != NULL) {
                    right_prev = right_temp;
                    right_temp = right_temp->next;
                }
                right_prev->next = NULL;
                free(right_temp);
            }
            *max -= 20;
            //free 10 units from left side
            for (int i = 0; i < 10; i++) {
                left_temp = *left_head;
                while (left_temp->next != NULL) {
                    left_prev = left_temp;
                    left_temp = left_temp->next;
                }
                left_prev->next = NULL;
                free(left_temp);
            }
            *min -= 10;
        }
        printf("MAX -> %d\n", *max);
        printf("MIN -> %d\n\n", *min);
    }

}

void kpp(left **left_head, right **right_head, int *max, int *min) {
    left *left_temp = *left_head;
    right *right_temp = *right_head;
    right *right_prev;
    left *left_prev;

    while (1) {
        if (*max <= 15 && *min <= 15) {
            printf("\nalmost at the end\n=================\n");
            printf("right side first\n");
            //right side vehicles
            while (*max > 0) {
                right_temp = *right_head;
                while (right_temp->next != NULL) {
                    right_prev = right_temp;
                    right_temp = right_temp->next;
                }
                right_prev->next = NULL;
                free(right_temp);
                //printf("#: %d\n", right_temp->val);
                (*max)--;
            }
            printf("\nright side done\n\n");

            printf("left side next\n");
            //right side vehicles
            while (*min > 0) {
                left_temp = *left_head;
                while (left_temp->next != NULL) {
                    left_prev = left_temp;
                    left_temp = left_temp->next;
                }
                left_prev->next = NULL;
                free(left_temp);
                //printf("#: %d\n", left_temp->val);
                (*min)--;
            }
            printf("\ndone\n=================\n");
            break;
        }
        for (int i = 0; i < 15; i++) {
            //right side vehicles
            right_temp = *right_head;
            while (right_temp->next != NULL) {
                right_prev = right_temp;
                right_temp = right_temp->next;
            }
            right_prev->next = NULL;
            free(right_temp);

            //left side vehicles
            left_temp = *left_head;
            while (left_temp->next != NULL) {
                left_prev = left_temp;
                left_temp = left_temp->next;
            }
            left_prev->next = NULL;
            free(left_temp);
        }
        *max -= 15;
        *min -= 15;
        if (*max < 100 && *min < 100) {
            printf("Under 100...\n");
            printf("max: %d\tmin: %d\n", *max, *min);
        }
    }
}




