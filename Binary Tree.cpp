#include <iostream>
using namespace std;

// Define the structure for the binary tree node
struct node {
   int value;           // Stores the value of the node
   struct node *leftChild, *rightChild;  // Pointers to left and right child nodes
};

// Function to create a new node with a given value
struct node *newNode(int value){
   struct node *temp = (struct node *)malloc(sizeof(struct node)); // Allocate memory for a new node
   temp->value = value;     // Set the node value
   temp->leftChild = temp->rightChild = NULL;  // Initialize left and right children as NULL
   return temp;  // Return the new node
}

// Function to perform in-order traversal (left, root, right) and print the node values
void print(struct node* root_node){
   if(root_node != NULL) {  // If the current node is not NULL
      print(root_node->leftChild);  // Recurse on the left child
      cout << "\n" << root_node->value;  // Print the value of the node
      print(root_node->rightChild);  // Recurse on the right child
   }
}

// Function to insert a node with a given value into the binary search tree
struct node* insert_node(struct node* node, int value){
   if(node == NULL) {  // If the tree is empty or we reached a NULL node, insert the new node here
      return newNode(value);
   }
   // If the value is less than the current node's value, go to the left child
   if(value < node->value) {
      node->leftChild = insert_node(node->leftChild, value);
   } 
   // If the value is greater than the current node's value, go to the right child
   else if(value > node->value) {
      node->rightChild = insert_node(node->rightChild, value);
   }
   // If the value is equal to the current node's value, do nothing (no duplicates in BST)
   return node;  // Return the (unchanged) node pointer
}

// Main function
int main(){
   cout << "Binary Tree \n\n";

   // Initialize the root of the binary tree
   struct node *root_node = NULL;

   // Insert nodes with values into the binary search tree
   root_node = insert_node(root_node, 10); // Insert 10 as the root node
   insert_node(root_node , 10);             // Insert another 10 (duplicate, won't be added)
   insert_node(root_node , 30);             // Insert 30
   insert_node(root_node , 25);             // Insert 25
   insert_node(root_node , 36);             // Insert 36
   insert_node(root_node , 56);             // Insert 56
   insert_node(root_node , 6);              // Insert 6

   // Print the values of the tree in in-order
   print(root_node);

   return 0;  // End of the program
}
