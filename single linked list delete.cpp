#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
void insertAtBeginning(struct Node** head_ref,int new_data){
	struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
void deleteNode(struct Node** head_ref, int key){
	struct Node* temp = *head_ref;
	struct Node* prev = NULL;
	if(temp !=NULL && temp->data == key){
		*head_ref = temp->next;
		free(temp);
		return;
	}
	while(temp != NULL && temp->data != key){
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL){
		printf("key not found in the list.\n");
		return;
	}
	prev->next = temp->next;
	free(temp);
}
void printList(struct Node* node) {
	while (node!= NULL){
		printf("%d",node->data);
		node=node->next;
	}
	printf("\n");
}
int main(){
	struct Node* head = NULL;
	insertAtBeginning(&head, 7);
	insertAtBeginning(&head, 5);
	insertAtBeginning(&head, 3);
	insertAtBeginning(&head, 1);
	printf("Original linked list: ");
	printList(head);
	deleteNode(&head, 5);
	printf("linked list after deletion: ");
	printList(head);
	return 0;
}
