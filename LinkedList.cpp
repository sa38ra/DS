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

void reverse(struct node** head_ref) {
    struct node* prev = NULL;     // Pointer to hold the previous node (initially NULL)
    struct node* current = *head_ref; // Pointer to traverse the list, starting from the head
    struct node* next = NULL;     // Pointer to hold the next node temporarily

    // Traverse the entire list
    while (current != NULL) {
        next = current->next;     // Save the next node
        current->next = prev;     // Reverse the current node's pointer to point to the previous node
        prev = current;           // Move the prev pointer one step forward
        current = next;           // Move the current pointer one step forward
    }

    // After the loop, prev will point to the new head of the list
    *head_ref = prev;
}

int main() {
    // Insert elements into the linked list
    // `insertFirst` adds elements at the beginning of the list
    insertFirst(1, 10); // Add a node with key=1 and data=10
    insertFirst(2, 20); // Add a node with key=2 and data=20
    insertFirst(3, 30); // Add a node with key=3 and data=30
    insertFirst(4, 1);  // Add a node with key=4 and data=1
    insertFirst(5, 40); // Add a node with key=5 and data=40
    insertFirst(6, 56); // Add a node with key=6 and data=56

    // Display the original list
    cout << "Original List: ";
    printList();

    // Delete all nodes from the list one by one
    while (!isEmpty()) {
        struct node* temp = deleteFirst(); // Delete the first node and store it in temp
        cout << "\nDeleted value: ";
        cout << temp->key << "," << temp->data; // Print the key and data of the deleted node
    }

    // Check and print the list after all nodes are deleted
    cout << "\nList after deleting all items: ";
    printList();

    // Restore the list by reinserting the same elements
    insertFirst(1, 10);
    insertFirst(2, 20);
    insertFirst(3, 30);
    insertFirst(4, 1);
    insertFirst(5, 40);
    insertFirst(6, 56);

    cout << "\nRestored List: ";
    printList(); // Display the restored list
    cout << "\n";

    // Search for a node with key=4
    struct node* foundLink = find(4);
    if (foundLink != NULL) {
        cout << "Element found: ";
        cout << foundLink->key << "," << foundLink->data; // Print the found node's key and data
        cout << "\n";
    } else {
        cout << "Element not found.\n";
    }

    // Delete a specific node with key=4
    delet(4);
    cout << "List after deleting an item: ";
    printList(); // Display the list after deletion
    cout << "\n";

    // Try to find the node with key=4 again (it should not be found)
    foundLink = find(4);
    if (foundLink != NULL) {
        cout << "Element found: ";
        cout << foundLink->key << "," << foundLink->data;
        cout << "\n";
    } else {
        cout << "Element not found.\n";
    }

    // Sort the linked list in ascending order by data
    sort();
    cout << "List after sorting the data: ";
    printList();

    // Reverse the linked list
    reverse(&head);
    cout << "\nList after reversing the data: ";
    printList();

    // Keep the console open to view the results
    int x;
    cin >> x;

    return 0;
}
