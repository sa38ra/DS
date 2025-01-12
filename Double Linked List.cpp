#include <iostream>  
using namespace std;

// Define a structure for the doubly linked list node
struct node {
    int data;          // To store the value of the node
    node* next;        // Pointer to the next node
    node* prev;        // Pointer to the previous node
};

node* head = NULL; // Initialize the head of the list to NULL (empty list)

// Function to insert a node at the end of the list
void insertNode(int value) {
    node* newNode = new node; // Allocate memory for a new node
    newNode->data = value;    // Set the node's data to the given value
    newNode->next = NULL;     // Set the next pointer to NULL (end of list)
    newNode->prev = NULL;     // Set the previous pointer to NULL (new node)

    if (head == NULL) {
        // If the list is empty, make the new node the head
        head = newNode;
    } else {
        // Traverse to the last node
        node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        // Link the new node at the end of the list
        last->next = newNode;
        newNode->prev = last;
    }
}

// Function to display the list
void display() {
    if (head == NULL) {
        // If the list is empty, print an error message
        cout << "Empty List Can't Display...!" << endl;
    } else {
        // Traverse and print each node's data
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl; // Add a newline after displaying the list
}

// Function to insert a node at the front of the list
void insertAtFront(int value) {
    node* newNode = new node; // Create a new node
    newNode->data = value;    // Set the node's data
    newNode->next = head;     // Point the new node's next to the current head
    newNode->prev = NULL;     // The new node has no previous node

    if (head != NULL) {
        // If the list is not empty, update the current head's previous pointer
        head->prev = newNode;
    }
    // Update the head pointer to the new node
    head = newNode;
}

// Function to insert a node after a specific value
void insertBetween(int value, int Aftervalue) {
    node* newNode = new node; // Create a new node
    newNode->data = value;    // Set the node's data
    node* current = head;     // Start at the head

    // Traverse to find the node with the given value
    while (current != NULL && current->data != Aftervalue) {
        current = current->next;
    }

    if (current == NULL) {
        // If the given value is not found, do nothing
        cout << "Value " << Aftervalue << " not found in the list." << endl;
        delete newNode; // Free the unused memory
        return;
    }

    // Insert the new node after the current node
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        // Update the next node's previous pointer
        current->next->prev = newNode;
    }
    // Update the current node's next pointer
    current->next = newNode;
}

// Function to delete a node with a specific value
void deleteNode(int value) {
    if (head == NULL) {
        // If the list is empty, print an error message
        cout << "Empty List Can't Remove." << endl;
        return;
    }

    node* current = head; // Start at the head

    if (current->data == value) {
        // If the head node is to be deleted
        head = current->next; // Move the head pointer to the next node
        if (head != NULL) {
            head->prev = NULL; // Update the new head's previous pointer
        }
        delete current; // Free the memory of the deleted node
        return;
    }

    // Traverse to find the node to delete
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        // If the value is not found, do nothing
        cout << "Value " << value << " not found in the list." << endl;
        return;
    }

    // Update the links to remove the current node
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    delete current; // Free the memory of the deleted node
}

// Main function to demonstrate the functionality
int main() {
    // Insert nodes at the end
    insertNode(10);
    insertNode(20);
    insertNode(30);
    display(); // Output: 10 20 30

    // Insert at the front
    insertAtFront(5);
    display(); // Output: 5 10 20 30

    // Insert between two nodes
    insertBetween(8, 5); // Insert 8 after 5
    display();           // Output: 5 8 10 20 30

    // Delete a node
    deleteNode(8); // Remove 8
    display();     // Output: 5 10 20 30

    return 0;
}
