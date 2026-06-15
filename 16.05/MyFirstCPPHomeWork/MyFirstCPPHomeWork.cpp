#include <iostream>
using namespace std;

//1

const int N = 5;

void printList(int mobile[], int home[]) {
    cout << "Mobile\tHome\n";
    for (int i = 0; i < N; i++) {
        cout << mobile[i] << "\t" << home[i] << endl;
    }
}

void sortByMobile(int mobile[], int home[]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (mobile[j] > mobile[j + 1]) {
                swap(mobile[j], mobile[j + 1]);
                swap(home[j], home[j + 1]);
            }
        }
    }
}

void sortByHome(int mobile[], int home[]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (home[j] > home[j + 1]) {
                swap(home[j], home[j + 1]);
                swap(mobile[j], mobile[j + 1]);
            }
        }
    }
}


//2

void improvedBubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int swaps = 0;

        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }

        if (swaps == 0) {
            break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


//3

void flip(int arr[], int index) {
    int left = 0;

    while (left < index) {
        swap(arr[left], arr[index]);
        left++;
        index--;
    }
}

int findMax(int arr[], int size) {
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    return maxIndex;
}

void pancakeSort(int arr[], int size) {
    for (int currentSize = size; currentSize > 1; currentSize--) {
        int maxIndex = findMax(arr, currentSize);

        if (maxIndex != currentSize - 1) {
            flip(arr, maxIndex);
            flip(arr, currentSize - 1);
        }
    }
}

int main() {
    // Task 1 - demonstration
    int mobile[N] = { 38050, 38067, 38093, 38099, 38063 };
    int home[N] = { 24567, 12345, 98765, 45678, 56789 };

    int choice;

    do {
        cout << "\nPhone Directory Menu\n";
        cout << "1. Sort by mobile numbers\n";
        cout << "2. Sort by home numbers\n";
        cout << "3. Show phone list\n";
        cout << "4. Continue to other tasks\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sortByMobile(mobile, home);
            cout << "Sorted by mobile numbers.\n";
            break;

        case 2:
            sortByHome(mobile, home);
            cout << "Sorted by home numbers.\n";
            break;

        case 3:
            printList(mobile, home);
            break;

        case 4:
            cout << "Leaving phone directory.\n";
            break;

        default:
            cout << "Wrong option.\n";
        }

    } while (choice != 4);


    // Task 2 - demonstration
    cout << "\nImproved Bubble Sort\n";

    int arr1[] = { 5, 2, 9, 1, 3, 8, 7, 4, 6, 10 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Before sorting: ";
    printArray(arr1, size1);

    improvedBubbleSort(arr1, size1);

    cout << "After sorting: ";
    printArray(arr1, size1);


    // Task 3 - demonstration
    cout << "\nPancake Sort\n";

    int arr2[] = { 3, 6, 1, 5, 2, 4 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Before sorting: ";
    printArray(arr2, size2);

    pancakeSort(arr2, size2);

    cout << "After sorting: ";
    printArray(arr2, size2);
}