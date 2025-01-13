#include <iostream>  // Standard input/output library
#include <conio.h>   // For _getch(), specific to Windows
using namespace std;

int main() {
    int array[100]; // Array to store up to 100 elements
    int i, j, num, temp; // Variables for loop counters, number of elements, and temporary storage

    // Prompt the user to enter the number of elements
    cout << "Enter the value of num \n";
    cin >> num; // Input the number of elements

    // Prompt the user to enter the elements of the array
    cout << "Enter the elements one by one \n";
    for (i = 0; i < num; i++) {
        cin >> array[i]; // Input each element
    }

    /* Bubble sorting begins */
    // Outer loop runs for each element (n iterations)
    for (i = 0; i < num; i++) {
        // Inner loop for comparing adjacent elements
        for (j = 0; j < (num - i - 1); j++) {
            if (array[j] > array[j + 1]) { // Compare adjacent elements
                // Swap elements if they are in the wrong order
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Output the sorted array
    cout << "Sorted array is...\n";
    for (i = 0; i < num; i++) {
        cout << array[i] << "\n"; // Print each element of the sorted array
    }

    _getch(); // Pause the console window, waiting for a key press
    return 0; // End of program
}
