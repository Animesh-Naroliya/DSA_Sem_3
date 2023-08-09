#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int size = 0;
int arr[MAX_SIZE];

void Display_Array() {
    cout << "Linear Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Input_Array() {
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter " << size << " elements separated by space: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void Insert_Element(int index, int value) {
    if (size < MAX_SIZE && index >= 0 && index <= size) {
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
        size++;
        cout << "Element inserted at index " << index << "." << endl;
        cout << "The updated array is: ";
        Display_Array();
    } else {
        cout << "Invalid index or array is full. Cannot insert element." << endl;
    }
}

void Delete_Element(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element deleted from index " << index << "." << endl;
        cout << "The updated array is: ";
        Display_Array();
    } else {
        cout << "Invalid index. Cannot delete element." << endl;
    }
}

int Find_Location(int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            cout << "The element " << element << " is at index: " << i << endl;
            return i;
        }
    }
    cout << "Element not found in the array." << endl;
    return -1;
}

int main() {
    Input_Array();
    int choice, index, element, value;

    while (true) {
        cout << "\nMENU:" << endl;
        cout << "1. Insert a new element" << endl;
        cout << "2. Delete an element" << endl;
        cout << "3. Find the location of an element" << endl;
        cout << "4. Display elements of the linear array" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the index to insert the element: ";
                cin >> index;
                cout << "Enter the value to insert: ";
                cin >> value;
                Insert_Element(index, value);
                break;
            case 2:
                cout << "Enter the index to delete the element: ";
                cin >> index;
                Delete_Element(index);
                break;
            case 3:
                cout << "Enter the element to find its location: ";
                cin >> element;
                Find_Location(element);
                break;
            case 4:
                Display_Array();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
