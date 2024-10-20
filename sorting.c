#include <stdio.h>
#include <conio.h>  // Add this to use getch()

// Global variables for iteration
int i, j, t;

// Swap function used by Quick Sort and Heap Sort
void swap(int* a, int* b) {
    t = *a;
    *a = *b;
    *b = t;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    i = (low - 1);
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heapify for Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n) {
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to display the menu and let user select a sorting algorithm
void menu() {
    printf("Select a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Quick Sort\n");
    printf("4. Heap Sort\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  // Initial array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    menu();
    scanf("%d", &choice);  // Take user input for sorting algorithm choice

    // Switch case to perform sorting based on user's choice
    switch (choice) {
        case 1:
            printf("You chose Bubble Sort:\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("You chose Insertion Sort:\n");
            insertionSort(arr, n);
            break;
        case 3:
            printf("You chose Quick Sort:\n");
            quickSort(arr, 0, n - 1);
            break;
        case 4:
            printf("You chose Heap Sort:\n");
            heapSort(arr, n);
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            return 0;
    }

    // Print the sorted array
    printf("Sorted array: \n");
    printArray(arr, n);

    getch();  // Wait for user input before closing the window
    return 0;
}
