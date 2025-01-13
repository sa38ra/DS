#include <iostream>
using namespace std;

// Function for insertion sort (provided without modifications)
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    // Outer loop: Iterate through each element of the array starting from the second element.
    for (i = 1; i < n; i++) { 
        // The current element to be inserted into the sorted portion of the array.
        key = arr[i]; 
        // Index of the last element in the sorted portion of the array.
        j = i - 1; 

        // Inner loop: Shift elements of the sorted portion of the array that are greater than `key` to the right.
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; // Shift element to the next position.
            j = j - 1; // Move to the previous element.
        } 
        // Place the `key` in its correct position within the sorted portion.
        arr[j + 1] = key; 
    } 
} 


// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int n;

    // User input for the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // User input for array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Display the array before sorting
    cout << "Original array: ";
    printArray(arr, n);

    // Call the insertionSort function
    insertionSort(arr, n);

    // Display the array after sorting
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
