#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void deletei(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    struct Node* previous = NULL;
    if (current != NULL && current->data == value) {
        head = current->next;
        free(current);
        return;
    }
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Value not found in the list\n");
        return;
    }
    previous->next = current->next;
    free(current);
}

void traverse() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    printf("List: ");
    traverse();
    deletei(20);
    printf("After deleting 20: ");
    traverse();
    deletei(10);
    printf("After deleting 10: ");
    traverse();
    return 0;
}
