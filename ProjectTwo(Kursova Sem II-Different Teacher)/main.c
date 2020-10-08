#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


//DATA STRUCTURE
typedef struct {
    char id[20];
    char title[80];
    char author[50];
    float price;
    int publish_year;
    char publisher[80];
}t_lib;



//NODE STRUCTURE
typedef struct node {
    t_lib data;
    struct node *next;
}t_node;



//FUNCTION PROTOTYPES
void add_new_unit(t_node**, char *);
void delete_list(t_node**);
void add_tail(t_node **head, t_lib temp_storage);
void read_list(t_node **head, char *file_name);
void search_by_title(t_node **head, char*);
void search_by_author(t_node **head, char *u_author);
void update_by_id(t_node **head, char *u_id, char*);


int main() {
    t_node *head = NULL;

    char *file_name = "info.bin";
    FILE *temp_fp = fopen(file_name, "rb");
    if (temp_fp == NULL) {
        temp_fp = fopen(file_name, "wb");
    }
    fclose(temp_fp);

    FILE *tp = fopen("ids.txt", "r");
    if (tp == NULL) {
        tp = fopen("ids.txt", "w");
    }
    fclose(tp);
    t_lib temp_storage;

    int answer;
    int check = 0;
    char *u_title  = (char*) malloc(sizeof(char)*80);
    char *u_author = (char*) malloc(sizeof(char)*50);
    char *u_id     = (char*) malloc(sizeof(char)*20);
    char *temp_id  = (char*) malloc(sizeof(char)*20);

    while(1) {
        printf("\n1. Add new\n2. Update by id\n3. Search by title\n4. Search by author\n5. Exit\nAnswer: ");
        scanf("%d", &answer);

        if (answer == 1) {
            tp = fopen("ids.txt", "r");
            printf("\n");
            printf("Type in info\n======================\n");
            fflush(stdin);
            gets(temp_storage.id);
            gets(temp_storage.title);
            gets(temp_storage.author);
            scanf("%f", &temp_storage.price);
            scanf("%d", &temp_storage.publish_year);
            fflush(stdin);
            gets(temp_storage.publisher);

            while (fscanf(tp, "%s", temp_id) != EOF) {
                if (strcmp(temp_id, temp_storage.id) == 0) {
                    printf("ID already exists\nTry again\n");
                    fclose(tp);
                    check = 1;
                    break;
                }
            }

            if (check != 1) {
                add_tail(&head, temp_storage);
                add_new_unit(&head, file_name);
                printf("\n");
            }
            check = 0;
        }
        else if (answer == 2) {
            printf("\n");
            printf("Type in the desirable id: ");
            fflush(stdin);
            gets(u_id);

            delete_list(&head);
            read_list(&head, file_name);
            update_by_id(&head, u_id, file_name);
        }
        else if (answer == 3) {
            printf("\n");
            printf("Type in the desirable book title: ");
            fflush(stdin);
            gets(u_title);

            delete_list(&head);
            read_list(&head, file_name);
            search_by_title(&head, u_title);
        }
        else if (answer == 4) {
            printf("\n");
            printf("Type in the desirable author: ");
            fflush(stdin);
            gets(u_author);

            delete_list(&head);
            read_list(&head, file_name);
            search_by_author(&head, u_author);
        }
        else if (answer == 5) {
            delete_list(&head);
            free(u_title);
            free(u_id);
            free(u_author);
            free(temp_id);
            return 0;
        }
    }
}


//FUNCTIONS
void delete_list(t_node **head) {
    t_node *current = *head;
    t_node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void add_tail(t_node **head, t_lib temp_storage) {
    t_node *temp = *head;


    t_node *new_node = (t_node*) malloc(sizeof(t_node));
    new_node->data = temp_storage;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}


void add_new_unit(t_node **head, char *file_name) {
    FILE *fp;
    t_node *temp = *head;
    t_lib temp_storage;


    fp = fopen(file_name, "ab");

    if (fp == NULL) {
        printf("cant open file...\n");
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp_storage = temp->data;
    FILE *tp = fopen("ids.txt", "a");
    fprintf(tp, "%s\n", temp_storage.id);
    fclose(tp);
    if (fwrite(&temp_storage, sizeof(t_lib), 1, fp) == 1) {
        //printf("writing successful\n\n");
    }
    else
        printf("error writing...\n");

    fclose(fp);
}

void read_list(t_node **head, char *file_name) {
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("cant open the file\n");
        return;
    }

    t_lib temp_storage;
    while (!feof(fp)) {
        fread(&temp_storage, sizeof(t_lib), 1, fp);
        add_tail(head, temp_storage);
    }
    fclose(fp);
}

void search_by_title(t_node **head, char *u_title) {
    t_node *temp = *head;

    printf("=====================\n");
    while (temp->next != NULL) {
        if (strcmp(u_title, temp->data.title) == 0) {
            printf("%s\n%s\n%s\n%.2f\n%d\n%s\n\n",
               temp->data.id, temp->data.title, temp->data.author, temp->data.price, temp->data.publish_year, temp->data.publisher);
        }
        temp = temp->next;
    }
    printf("=====================\n");
}

void search_by_author(t_node **head, char *u_author) {
    t_node *temp = *head;

    printf("=====================\n");
    while (temp->next != NULL) {
        if (strcmp(u_author, temp->data.author) == 0) {
            printf("%s\n%s\n%s\n%.2f\n%d\n%s\n\n",
               temp->data.id, temp->data.title, temp->data.author, temp->data.price, temp->data.publish_year, temp->data.publisher);
        }
        temp = temp->next;
    }
    printf("=====================\n");
}

void update_by_id(t_node **head, char *u_id, char *file_name) {
    t_node *temp = *head;
    int answer;
    t_lib temp_storage;

    printf("=====================\n");
    while (temp->next != NULL) {
        if (strcmp(u_id, temp->data.id) == 0) {
            printf("Update attribute\n1. price\n2. publishing year\nAnswer: ");
            scanf("%d", &answer);

            if (answer == 1) {
                float new_price;
                printf("New price: ");
                scanf("%f", &new_price);
                temp->data.price = new_price;
            }
            else {
                int new_year;
                printf("New year: ");
                scanf("%d", &new_year);
                temp->data.publish_year = new_year;
            }
        }
        temp = temp->next;
    }

    FILE *fp = fopen(file_name, "wb");
    temp = *head;
    while (temp->next != NULL) {
        temp_storage = temp->data;
        if (fwrite(&temp_storage, sizeof(t_lib), 1, fp) == 1) {
            //printf("writing successful\n\n");
        }
        else
            printf("error writing...\n");
        temp = temp->next;
    }
    fclose(fp);
    printf("=====================\n");
}



