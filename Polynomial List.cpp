#include <iostream>
#include <cstdlib> // For malloc
using namespace std;

struct Node {
    int coeff; // Coefficient of the term
    int pow;   // Power of the term
    struct Node* next; // Pointer to the next node
};

// Function to create a new node for the polynomial
void create_node(int coeff, int pow, struct Node** temp) {
    struct Node *r, *z;
    z = *temp;
    if (z == NULL) {
        // Create the first node
        r = (struct Node*)malloc(sizeof(struct Node));
        r->coeff = coeff;
        r->pow = pow;
        *temp = r;
        r->next = NULL;
    } else {
        // Append to the existing list
        while (z->next != NULL)
            z = z->next;
        r = (struct Node*)malloc(sizeof(struct Node));
        r->coeff = coeff;
        r->pow = pow;
        r->next = NULL;
        z->next = r;
    }
}

// Function to add two polynomials
void polyadd(struct Node* poly1, struct Node* poly2, struct Node* poly) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        } else {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if (poly1 != NULL || poly2 != NULL) {
            poly->next = (struct Node*)malloc(sizeof(struct Node));
            poly = poly->next;
            poly->next = NULL;
        }
    }
    while (poly1 != NULL) {
        poly->pow = poly1->pow;
        poly->coeff = poly1->coeff;
        poly1 = poly1->next;
        if (poly1 != NULL) {
            poly->next = (struct Node*)malloc(sizeof(struct Node));
            poly = poly->next;
            poly->next = NULL;
        }
    }
    while (poly2 != NULL) {
        poly->pow = poly2->pow;
        poly->coeff = poly2->coeff;
        poly2 = poly2->next;
        if (poly2 != NULL) {
            poly->next = (struct Node*)malloc(sizeof(struct Node));
            poly = poly->next;
            poly->next = NULL;
        }
    }
}

// Function to display the polynomial
void show(struct Node* node) {
    while (node != NULL) {
        cout << node->coeff << "x^" << node->pow;
        node = node->next;
        if (node != NULL && node->coeff >= 0) {
            cout << " + ";
        }
    }
    cout << endl;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

    // Create first polynomial: 5x^2 + 4x^1 + 2x^0
    create_node(5, 2, &poly1);
    create_node(4, 1, &poly1);
    create_node(2, 0, &poly1);

    // Create second polynomial: -5x^1 - 5x^0
    create_node(-5, 1, &poly2);
    create_node(-5, 0, &poly2);

    cout << "1st Polynomial: ";
    show(poly1);

    cout << "2nd Polynomial: ";
    show(poly2);

    // Add the two polynomials
    poly = (struct Node*)malloc(sizeof(struct Node));
    polyadd(poly1, poly2, poly);

    cout << "Resultant Polynomial: ";
    show(poly);

    return 0;
}
