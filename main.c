#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} node;

void insert();
void reverse();
void sort();
void clear_duplicates();
void display();
void add(node*, node*);

node *create(), *head;

const char *operation_list = "\nAvailable Operations:\n"
               "1.Insert front\n"
               "2.Insert back\n"
               "3.Reverse\n"
               "4.Sort\n"
               "5.Clear duplicates\n"
               "6.Display\n"
               "7.Exit\n";


int main() {
    printf("Machine Exercise 1\n");
    printf("Submitted by: Robert Sardilla\n");
    printf("Submitted to: Vincent Lomibao\n");

    head = create();
    int operation = 0;
    printf(operation_list);

    while (operation != 7) {

        printf("\nEnter your operation: ");

        scanf("%d", &operation);

        switch (operation) {
        case 1:
            insert("front", head);
            break;

        case 2:
            insert("back", head->prev);
            break;

        case 3:
            reverse();
            break;

        case 4:
            sort();
            break;

        case 5:
            clear_duplicates();
            break;

        case 6:
            display();
            break;

        case 7:
            printf("Exiting\n");
            break;

        default:
            printf(operation_list);
            printf("\nInvalid operation, pls try again\n");
        }

    }

    return 0;
}


void insert(char *name, node *prev) {
    node* ptr = create();

    if (ptr != NULL) {
        printf("\nEnter a value to insert in the %s: ", name);
        scanf("%d", &ptr->data);
        add(prev, ptr);


        printf("Successfully inserted %d in the %s", ptr->data, name);
        display();
    }
}


void reverse() {
    node *prev = head->prev;
    head->next = prev;

    while(prev != head) {
        printf("Current prev val %d", prev->data);
        node *nextPrev = prev->prev;

        prev->prev = prev->next;
        prev->next = nextPrev;
        prev = nextPrev;
    }

    printf("Successfully reversed\n");
    display();
}


void sort() {
    node *pivot = head->next;

    while (pivot != head) {
        node *next = pivot->next;


        while (next != head) {

        }

    }
}


void clear_duplicates() {

}


void display() {
    node *next = head->next;

    printf("\nCurrent values: [ ");
    while (next != head) {
        printf("%d ", next->data);
        next = next->next;
    }
    printf("]\n");
}


node *create(){
    node* ptr = (node*)malloc(sizeof(node));

    if (ptr == NULL){
        printf("Error: Memory Overflow\n");
    }
    else {
        ptr->prev = ptr;
        ptr->next = ptr;
    }

    return ptr;
}


void add(node *prev, node *ptr) {
    ptr->prev = prev;
    ptr->next = prev->next;
    prev->next->prev = ptr;
    prev->next = ptr;
}

