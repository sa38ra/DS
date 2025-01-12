#include <iostream>
#include <cstdlib> // For malloc function
using namespace std;

// Define a structure for a node in the linked list
struct node {
    int data;            // Data stored in the node
    int key;             // Unique key for identifying the node
    struct node* next;   // Pointer to the next node in the list
};

// Global pointers for the head of the list and for traversals
struct node* head = NULL;    // Pointer to the first node (head) of the list
struct node* current = NULL; // Temporary pointer used for traversal

// Function to insert a new node at the beginning of the list
void insertFirst(int key, int data) {
    // Allocate memory for a new node
    struct node* link = (struct node*)malloc(sizeof(struct node));
    
    // Assign the given key and data to the new node
    link->key = key;
    link->data = data;

    // Make the new node point to the current head of the list
    link->next = head;

    // Update the head to point to the new node
    head = link;
}

// Function to print all nodes in the list
void printList() {
    struct node* ptr = head; // Start from the head of the list
    cout << "\n[ ";          // Opening bracket for the list display

    // Traverse the list until the end
    while (ptr != NULL) {
        // Print the key and data of the current node
        cout << ptr->key << "," << ptr->data << "\t";
        ptr = ptr->next; // Move to the next node
    }

    cout << " ]"; // Closing bracket for the list display
}

// Function to delete the first node of the list
struct node* deleteFirst() {
    struct node* tempLink = head; // Save the current head node

    // If the list is not empty, update the head pointer
    if (head != NULL) {
        head = head->next; // Move the head to the next node
    }

    return tempLink; // Return the deleted node
}

// Function to check if the list is empty
bool isEmpty() {
    return head == NULL; // Return true if head is NULL, false otherwise
}

// Function to calculate the length of the list
int length() {
    int length = 0;          // Initialize the counter
    struct node* current = head; // Start from the head of the list

    // Traverse the list and count nodes
    while (current != NULL) {
        length++;            // Increment the counter for each node
        current = current->next; // Move to the next node
    }

    return length; // Return the total count of nodes
}

// Function to find a node by its key
struct node* find(int key) {
    struct node* current = head; // Start from the head of the list

    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // Traverse the list until the key is found or the end is reached
    while (current->key != key) {
        if (current->next == NULL) { // If the key is not found
            return NULL;
        }
        current = current->next; // Move to the next node
    }

    return current; // Return the node with the matching key
}

// Function to delete a node by its key
struct node* delet(int key) {
    struct node* current = head;  // Start from the head of the list
    struct node* previous = NULL; // Pointer to the previous node

    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // Traverse the list until the key is found or the end is reached
    while (current->key != key) {
        if (current->next == NULL) { // If the key is not found
            return NULL;
        }

        // Move to the next node, keeping track of the previous node
        previous = current;
        current = current->next;
    }

    // If the node to be deleted is the head
    if (current == head) {
        head = head->next; // Update head to the next node
    } else {
        // Bypass the node to delete it
        previous->next = current->next;
    }

    return current; // Return the deleted node
}

// Function to sort the list in ascending order using bubble sort
void sort() {
    int i, j, k, tempKey, tempData; // Variables for sorting
    struct node* current;          // Pointer to the current node
    struct node* next;             // Pointer to the next node

    int size = length(); // Get the number of nodes in the list
    k = size;            // Set the number of passes for sorting

    // Outer loop for the number of passes
    for (i = 0; i < size - 1; i++, k--) {
        current = head;         // Start at the head of the list
        next = head->next;      // Start at the second node

        // Inner loop for comparing adjacent nodes
        for (j = 1; j < k; j++) {
            if (current->data > next->data) { // If nodes are out of order
                // Swap the data values of the nodes
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                // Swap the keys of the nodes
                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }

            // Move to the next pair of nodes
            current = current->next;
            next = next->next;
        }
    }
}

// Main function to demonstrate the linked list operations
int main() {
    insertFirst(1, 10); // Insert node with key=1, data=10
    insertFirst(2, 20); // Insert node with key=2, data=20
    insertFirst(3, 30); // Insert node with key=3, data=30

    cout << "Original list:";
    printList(); // Display the list

    sort(); // Sort the list
    cout << "\nSorted list:";
    printList(); // Display the sorted list

    return 0;
}
