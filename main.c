#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} node;

void insert_front();
void insert_back();
void reverse();
void sort();
void clear_duplicates();
void display();

node *create_node(), *head;


int main() {
    printf("Machine Exercise 1\n");
    printf("Submitted by: Robert Sardilla\n");
    printf("Submitted to: Vincent Lomibao\n");

    head = create_node();
    int operation = 0;

    while (operation != 7) {
        printf("\nAvailable Operations\n"
               "1.Insert front\n"
               "2.Insert back\n"
               "3.Reverse\n"
               "4.Sort\n"
               "5.Clear duplicates\n"
               "6.Display\n"
               "7.Exit\n");

        printf("\nEnter your operation\n");
        scanf("%d", &operation);

        switch (operation) {
        case 1:
            insert_front();
            break;

        case 2:
            insert_back();
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
            printf("\nInvalid operation, pls try again\n");
        }

    }

    return 0;
}


node *create_node(){
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


void insert_front() {
    node* ptr = create_node();

    if (ptr != NULL) {
        printf("\nEnter value: ");
        scanf("%d", &ptr->data);

        ptr->prev = head;
        ptr->next = head->next;
        head->next->prev = ptr;
        head->next = ptr;
    }
}


void insert_back() {
    node* ptr = create_node();

    if (ptr != NULL) {
        printf("\nEnter a value: ");
        scanf("%d", &ptr->data);

        ptr->prev = head->prev;
        ptr->next = head;
        head->prev->next = ptr;
        head->prev = ptr;
    }
}


void reverse() {

}


void sort() {

}


void clear_duplicates() {

}


void display() {
    node* next = head->next;

    if(next == head){
        printf("\nNothing to display\n");
        return;
    }

    printf("\nValues\n");
    while (next != head) {
        printf("%d ", next->data);
        next = next->next;
    }
}

