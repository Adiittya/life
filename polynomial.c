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

int main() {
    struct PolyNode* poly1 = NULL;
    struct PolyNode* poly2 = NULL;
    struct PolyNode* sum = NULL;

    // Inserting terms for the first polynomial (3x^3 + 5x^2 + 6)
    poly1 = insertNode(poly1, 3, 3);
    poly1 = insertNode(poly1, 5, 2);
    poly1 = insertNode(poly1, 6, 0);

    // Inserting terms for the second polynomial (2x^2 + 3x + 1)
    poly2 = insertNode(poly2, 2, 2);
    poly2 = insertNode(poly2, 3, 1);
    poly2 = insertNode(poly2, 1, 0);

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
