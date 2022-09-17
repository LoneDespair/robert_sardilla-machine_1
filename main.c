#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;

    struct Node *prev;
    struct Node *next;
} node;

void insert_front();
void insert_back();

node* head;
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

    head = create_node();
    int operation = 0;

    while (operation != 7) {
        printf("Available Operations\n"
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

        default:
            printf("Invalid operation, pls try again\n");
        }

    }

    return 0;
}


void insert_front() {
    node* ptr = create_node();

    if (ptr == NULL){
        return;
    }

    printf("Enter value:");
    scanf("%d", &ptr->data);

    printf("Result  %d:", ptr->data);

}



