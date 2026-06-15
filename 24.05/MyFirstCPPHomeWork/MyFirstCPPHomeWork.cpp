#include <iostream>
using namespace std;

//1

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}


//2

int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}


//3

int binaryToDecimal(int binary) {
    if (binary == 0)
        return 0;

    int lastDigit = binary % 10;
    return lastDigit + 2 * binaryToDecimal(binary / 10);
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


int main() {
    // Task 1 - demonstration
    cout << "=== Task 1: Linear Search ===\n";

    int arr1[] = { 5, 3, 8, 1, 9, 2, 7, 4, 6 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Array: ";
    printArray(arr1, n1);

    int key1 = 9;
    int result1 = linearSearch(arr1, n1, key1);

    if (result1 != -1)
        cout << "Key " << key1 << " found at index " << result1 << "\n";
    else
        cout << "Key " << key1 << " not found\n";

    int key2 = 10;
    int result2 = linearSearch(arr1, n1, key2);

    if (result2 != -1)
        cout << "Key " << key2 << " found at index " << result2 << "\n";
    else
        cout << "Key " << key2 << " not found\n";


    // Task 2 - demonstration
    cout << "\n=== Task 2: Binary Search ===\n";

    int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Array: ";
    printArray(arr2, n2);

    int key3 = 6;
    int result3 = binarySearch(arr2, n2, key3);

    if (result3 != -1)
        cout << "Key " << key3 << " found at index " << result3 << "\n";
    else
        cout << "Key " << key3 << " not found\n";

    int key4 = 10;
    int result4 = binarySearch(arr2, n2, key4);

    if (result4 != -1)
        cout << "Key " << key4 << " found at index " << result4 << "\n";
    else
        cout << "Key " << key4 << " not found\n";


    // Task 3 - demonstration
    cout << "\n=== Task 3: Binary to Decimal ===\n";

    int binary1 = 1101;
    cout << binary1 << " (binary) = " << binaryToDecimal(binary1) << " (decimal)\n";

    int binary2 = 101010;
    cout << binary2 << " (binary) = " << binaryToDecimal(binary2) << " (decimal)\n";

    int binary3 = 11111111;
    cout << binary3 << " (binary) = " << binaryToDecimal(binary3) << " (decimal)\n";
}