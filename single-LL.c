#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}
struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode) {
        newNode->next = head;
        head = newNode;
        printf("Element %d inserted at the beginning of the list.\n", data);
    }
    return head;
}
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Element %d not found in the list. Deletion failed.\n", key);
        return head;
    }
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Element %d deleted from the list.\n", key);
    return head;
}
void displayList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int choice, data, key;
    while (1) {
        clrscr();
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                head = insertNode(head, data);
                getch();
                break;
            case 2:
                if (head == NULL) {
                    printf("List is empty. Deletion failed.\n");
                    getch();
                } else {
                    printf("Enter the element to delete: ");
                    scanf("%d", &key);
                    head = deleteNode(head, key);
                    getch();
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("List is empty.\n");
                    getch();
                } else {
                    displayList(head);
                    getch();
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                getch();
        }
    }
    return 0;
}
