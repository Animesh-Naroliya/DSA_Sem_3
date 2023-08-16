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

void Delete_Element_By_Value(int value) {
    int found = -1;
    for (int i = 0; i < size; i++) {
        if (value == arr[i]) {
            found = i;
            break;
        }
    }
    
    if (found != -1) {
        for (int i = found; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element " << value << " is deleted from the array." << endl;
        cout << "Updated array: "<<endl;
        Display_Array();
    } else {
        cout << "Element not found in the array." << endl;
    }
}

void Delete_Element_By_Index(int index) {
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
    cout << "\n\nElement not found in the array." << endl;
    return 0;
}

int main() {
    Input_Array();
    int choice, index, element, value;

    while (true) {
        cout << "\nMENU:" << endl;
        cout << "1. Insert a new element" << endl;
        cout << "2. Delete an element by index" << endl;
        cout << "3. Delete an element by value" << endl;
        cout << "4. Find the location of an element" << endl;
        cout << "5. Display elements of the linear array" << endl;
        cout << "6. Exit" << endl;
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
                Delete_Element_By_Index(index);
                break;
            case 3:
                cout<<"Enter the value to delete in the array: ";
                cin >> value;
                Delete_Element_By_Value(value);
                break;
            case 4:
                cout << "Enter the element to find its location: ";
                cin >> element;
                Find_Location(element);
                break;
            case 5:
                Display_Array();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}
