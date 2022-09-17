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
void sever(node*);
int get_num();

node *create(), *head;

const char *operation_list =
        "\nAvailable Operations: (Pls use the number/id)\n"
            "  1.Insert front\n"
            "  2.Insert back\n"
            "  3.Reverse\n"
            "  4.Sort\n"
            "  5.Clear duplicates\n"
            "  6.Display\n"
            "  7.Exit\n";


int main() {
    printf("Machine Exercise 1\n");
    printf("Submitted by: Robert Sardilla\n");
    printf("Submitted to: Vincent Lomibao\n");

    printf(operation_list);
    head = create();
    int operation = 0;

    while (operation != 7) {
        printf("\nEnter your operation: ");
        operation = get_num();

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
            break;

        default:
            printf("\nInvalid operation, pls try again\n");
            printf(operation_list);
        }

    }

    printf("\nProgram exiting, thank you for using\n");

    return 0;
}


void insert(char *name, node *prev) {
    node* ptr = create();

    if (ptr != NULL) {
        printf("\nEnter a value to insert in the %s: ", name);
        ptr->data = get_num();
        add(prev, ptr);

        printf("Successfully inserted %d in the %s", ptr->data, name);
        display();
    }
}


void reverse() {
    node *prev = head;

    while(1) {
        node *nextPrev = prev->prev;

        prev->prev = prev->next;
        prev->next = nextPrev;
        prev = nextPrev;

        if (prev == head) {
            break;
        }
    }

    printf("Successfully reversed\n");
    display();
}


void sever(node *ptr) {
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
}


void sort() {
    node *pivot = head->next;

    while (pivot != head) {
        node *next = pivot->next;

        while (next != head) {
            if (pivot->data < next->data) {
                next = next->next;


            }
            else {
                node *pivot_prev = pivot->prev;

                sever(pivot);
                add(next, pivot);

                sever(next);
                add(pivot_prev, next);

                pivot = next;
                next = pivot->next;
            }
        }
        pivot = pivot->next;
    }
    printf("Sorting complete\n");
    display();
}


void clear_duplicates() {
    node *target = head->next;
    int count_duplicates = 0;

    while (target != head) {
        node *next = target->next;

        while (next != head) {
            node *future_next = next->next;

            if (target->data == next->data) {
                sever(next);
                free(next);
                count_duplicates += 1;
            }
            next = future_next;
        }
        target = target->next;
    }

    printf("Successfully cleared %d duplicates\n", count_duplicates);
    display();
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


int get_num() {
    char input[10];
    int num = 0;

    fflush(stdin);
    fgets(input, 10, stdin);
    sscanf(input, "%d", &num);
    return num;
}
