#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    return last;
}

struct Node* deleteNode(struct Node* last, int key) {
    if (last == NULL) {
        printf("List is empty. Deletion failed.\n");
        return last;
    }

    struct Node *current = last->next, *prev = last;
    struct Node* temp;

    // If the node to be deleted is the only node
    if (current == last && current->data == key) {
        free(current);
        last = NULL;
        printf("Node with data %d deleted from the list.\n", key);
        return last;
    }

    // If the node to be deleted is the first node
    if (current->data == key) {
        temp = current;
        last->next = current->next;
        free(temp);
        printf("Node with data %d deleted from the list.\n", key);
        return last;
    }

    // For other cases, traverse the list
    while (current != last) {
        if (current->data == key) {
            prev->next = current->next;
            free(current);
            printf("Node with data %d deleted from the list.\n", key);
            return last;
        }
        prev = current;
        current = current->next;
    }

    // Check if the node to be deleted is the last node
    if (current->data == key) {
        prev->next = last->next;
        free(current);
        last = prev;
        printf("Node with data %d deleted from the list.\n", key);
    } else {
        printf("Node with data %d not found in the list.\n", key);
    }
    return last;
}

void displayList(struct Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = last->next;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != last->next);
    printf("\n");
}

int main() {
    struct Node* last = NULL;
    int choice, data, key;
    while (1) {
        printf("Circular Linked List Menu:\n");
        printf("1. Insert a node at the end\n");
        printf("2. Delete a node by key\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                last = insertEnd(last, data);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                last = deleteNode(last, key);
                break;
            case 3:
                displayList(last);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
