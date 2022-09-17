#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
} node;

void insert_front();
void insert_back();
void display();

node* head, tail;
node* create_node(){
    node* ptr = (node*)malloc(sizeof(node));

    if (ptr == NULL){
        printf("Error: Memory Overflow\n");
    }

    return ptr;
}

int main() {
    printf("Machine Exercise 1\n");
    printf("Submitted by: Robert Sardilla\n");
    printf("Submitted to: Vincent Lomibao\n");

    int operation = 0;

    while (operation != 7) {
        printf("\nAvailable Operations\n"
               "1.Add node to the front\n"
               "2.Add node to the back\n"
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

        case 6:
            display();
            break;

        default:
            printf("Invalid operation, pls try again\n");
        }

    }

    return 0;
}


void insert_front() {
    node* ptr = create_node();

    if (ptr != NULL){
        printf("Enter value:");
        scanf("%d", &ptr->data);

        ptr->next = head;
        head = ptr;
    }
}


void display() {
    node* next = head;

    if(next == NULL){
        printf("Nothing to display\n");
        return;
    }

    printf("Values\n");
    while (next != NULL) {
        printf("%d ", next->data);
        next = next->next;
    }
}

