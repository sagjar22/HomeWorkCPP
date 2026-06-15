#include <iostream>
using namespace std;

//1

int* allocateArray(int n) {
    return new int[n];
}

void initArray(int* arr, int n) {
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void deleteArray(int* arr) {
    delete[] arr;
}

int* pushBack(int* arr, int& n, int value) {
    int* newArr = new int[n + 1];

    for (int i = 0; i < n; i++)
        newArr[i] = arr[i];

    newArr[n] = value;
    delete[] arr;
    n++;

    return newArr;
}

int* insertAt(int* arr, int& n, int index, int value) {
    int* newArr = new int[n + 1];

    for (int i = 0; i < index; i++)
        newArr[i] = arr[i];

    newArr[index] = value;

    for (int i = index; i < n; i++)
        newArr[i + 1] = arr[i];

    delete[] arr;
    n++;

    return newArr;
}

int* removeAt(int* arr, int& n, int index) {
    int* newArr = new int[n - 1];

    for (int i = 0; i < index; i++)
        newArr[i] = arr[i];

    for (int i = index + 1; i < n; i++)
        newArr[i - 1] = arr[i];

    delete[] arr;
    n--;

    return newArr;
}


//2

bool isPrime(int num) {
    if (num < 2)
        return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

int* removePrimes(int* arr, int n, int& newSize) {
    newSize = 0;

    for (int i = 0; i < n; i++)
        if (!isPrime(arr[i]))
            newSize++;

    int* newArr = new int[newSize];
    int idx = 0;

    for (int i = 0; i < n; i++)
        if (!isPrime(arr[i]))
            newArr[idx++] = arr[i];

    return newArr;
}


//3

void splitArray(int* arr, int n,
    int*& positives, int& posSize,
    int*& negatives, int& negSize,
    int*& zeros, int& zeroSize) {

    posSize = 0;
    negSize = 0;
    zeroSize = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) posSize++;
        else if (arr[i] < 0) negSize++;
        else zeroSize++;
    }

    positives = new int[posSize];
    negatives = new int[negSize];
    zeros = new int[zeroSize];

    int pi = 0, ni = 0, zi = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) positives[pi++] = arr[i];
        else if (arr[i] < 0) negatives[ni++] = arr[i];
        else zeros[zi++] = arr[i];
    }
}


int main() {
    // Task 1 - demonstration
    cout << "=== Task 1: Dynamic Array ===\n";

    int n = 5;
    int* arr = allocateArray(n);
    initArray(arr, n);

    cout << "Array: ";
    printArray(arr, n);

    arr = pushBack(arr, n, 99);
    cout << "After pushBack(99): ";
    printArray(arr, n);

    arr = insertAt(arr, n, 2, 55);
    cout << "After insertAt(2, 55): ";
    printArray(arr, n);

    arr = removeAt(arr, n, 1);
    cout << "After removeAt(1): ";
    printArray(arr, n);

    deleteArray(arr);


    // Task 2 - demonstration
    cout << "\n=== Task 2: Remove Primes ===\n";

    int n2 = 10;
    int* arr2 = new int[n2] { 4, 7, 10, 13, 6, 3, 8, 11, 9, 2 };

    cout << "Original: ";
    printArray(arr2, n2);

    int newSize;
    int* arr2filtered = removePrimes(arr2, n2, newSize);

    cout << "After removing primes: ";
    printArray(arr2filtered, newSize);

    delete[] arr2;
    delete[] arr2filtered;


    // Task 3 - demonstration
    cout << "\n=== Task 3: Split by Sign ===\n";

    int arr3[] = { 3, -1, 0, 7, -4, 0, 2, -9, 5, 0 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "Original: ";
    printArray(arr3, n3);

    int* positives;
    int* negatives;
    int* zeros;
    int posSize, negSize, zeroSize;

    splitArray(arr3, n3, positives, posSize, negatives, negSize, zeros, zeroSize);

    cout << "Positives: ";
    printArray(positives, posSize);

    cout << "Negatives: ";
    printArray(negatives, negSize);

    cout << "Zeros: ";
    printArray(zeros, zeroSize);

    delete[] positives;
    delete[] negatives;
    delete[] zeros;
}