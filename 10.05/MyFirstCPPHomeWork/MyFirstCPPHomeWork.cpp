#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function #1
void task1(int rows, int cols, int startNum) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];

    int value = startNum;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++, value *= 2)
            arr[i][j] = value;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
        cout << "\n";
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
}

// Function #2
void task2(int rows, int cols, int startNum) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];

    int value = startNum;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = value++;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
        cout << "\n";
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
}

// Function #3
void fillRandom(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = rand() % 10;
}

// Function #4
void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
        cout << "\n";
    }
}

// Function #5
void shiftRight(int** arr, int rows, int cols, int shifts) {
    int total = rows * cols;
    shifts %= total;

    int* flat = new int[total];
    int* shifted = new int[total];

    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            flat[k++] = arr[i][j];

    for (int i = 0; i < total; i++)
        shifted[(i + shifts) % total] = flat[i];

    k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = shifted[k++];

    delete[] flat;
    delete[] shifted;
}

// Function #6
void shiftLeft(int** arr, int rows, int cols, int shifts) {
    int total = rows * cols;
    shiftRight(arr, rows, cols, total - shifts % total);
}

// Function #7
void shiftDown(int** arr, int rows, int cols, int shifts) {
    shifts %= rows;

    int** temp = new int* [rows];
    for (int i = 0; i < rows; i++) {
        temp[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            temp[i][j] = arr[i][j];
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[(i + shifts) % rows][j] = temp[i][j];

    for (int i = 0; i < rows; i++)
        delete[] temp[i];
    delete[] temp;
}

// Function #8
void shiftUp(int** arr, int rows, int cols, int shifts) {
    shiftDown(arr, rows, cols, rows - shifts % rows);
}

// Function #9
void task3(int rows, int cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];

    fillRandom(arr, rows, cols);

    cout << "Original array:\n";
    printArray(arr, rows, cols);

    int shifts, direction;
    cout << "Enter number of shifts: ";
    cin >> shifts;
    cout << "Direction (1-left, 2-right, 3-up, 4-down): ";
    cin >> direction;

    switch (direction) {
    case 1: shiftLeft(arr, rows, cols, shifts);  break;
    case 2: shiftRight(arr, rows, cols, shifts); break;
    case 3: shiftUp(arr, rows, cols, shifts);    break;
    case 4: shiftDown(arr, rows, cols, shifts);  break;
    default: cout << "Invalid direction!\n";
    }

    cout << "Shifted array:\n";
    printArray(arr, rows, cols);

    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
}

int main() {
    srand(time(NULL));

    int rows, cols, startNum;

    // Task 1 - Create a 2D array where the first element equals a user-entered number, and each next element is the previous one multiplied by 2
    cout << "=== Task 1 ===\n";
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;
    cout << "Enter start number: ";
    cin >> startNum;
    task1(rows, cols, startNum);

    // Task 2 - Create a 2D array where the first element equals a user-entered number, and each next element is the previous one plus 1
    cout << "\n=== Task 2 ===\n";
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;
    cout << "Enter start number: ";
    cin >> startNum;
    task2(rows, cols, startNum);

    // Task 3 - Create a 2D array filled with random numbers, then cyclically shift it left, right, up, or down by a user-specified number of positions
    cout << "\n=== Task 3 ===\n";
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;
    task3(rows, cols);
}