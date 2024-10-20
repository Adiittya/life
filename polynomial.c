#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
};

// Function to create a new polynomial node
struct PolyNode* createNode(int coeff, int exp) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node in the polynomial
struct PolyNode* insertNode(struct PolyNode* poly, int coeff, int exp) {
    struct PolyNode* newNode = createNode(coeff, exp);
    if (poly == NULL) {
        return newNode;
    } else {
        struct PolyNode* temp = poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return poly;
}

// Function to print a polynomial
void printPoly(struct PolyNode* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct PolyNode* addPoly(struct PolyNode* poly1, struct PolyNode* poly2) {
    struct PolyNode* result = NULL;
    struct PolyNode* temp1 = poly1;
    struct PolyNode* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            result = insertNode(result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            result = insertNode(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else {
            result = insertNode(result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }

    // If any terms are remaining in poly1
    while (temp1 != NULL) {
        result = insertNode(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    // If any terms are remaining in poly2
    while (temp2 != NULL) {
        result = insertNode(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

// Function to take input for a polynomial
struct PolyNode* inputPoly() {
    struct PolyNode* poly = NULL;
    int n, coeff, exp;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        poly = insertNode(poly, coeff, exp);
    }

    return poly;
}

int main() {
    struct PolyNode* poly1 = NULL;
    struct PolyNode* poly2 = NULL;
    struct PolyNode* sum = NULL;

    // Taking input for the first polynomial
    printf("Input for the first polynomial:\n");
    poly1 = inputPoly();

    // Taking input for the second polynomial
    printf("Input for the second polynomial:\n");
    poly2 = inputPoly();

    // Display the two polynomials
    printf("Polynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    // Add the two polynomials
    sum = addPoly(poly1, poly2);

    // Display the sum of the two polynomials
    printf("Sum of the polynomials: ");
    printPoly(sum);

    return 0;
}
