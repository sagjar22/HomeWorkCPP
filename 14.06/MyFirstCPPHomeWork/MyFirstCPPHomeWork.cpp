#include <iostream>
using namespace std;

// function that finds the maximum value in an array
double findMax(int arr[], int size)
{
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// function that finds the minimum value in an array
double findMin(int arr[], int size)
{
    int minVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    return minVal;
}

// function that finds the average value in an array
double findAvg(int arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

// TASK: Action receives pointers to two arrays, their sizes, and a pointer to a function.
// It merges both arrays into one and applies the chosen function (max / min / avg) to the result.
double Action(int A[], int B[], int sizeA, int sizeB, double (*func)(int[], int))
{
    int totalSize = sizeA + sizeB;
    int* merged = new int[totalSize];

    for (int i = 0; i < sizeA; i++)
    {
        merged[i] = A[i];
    }
    for (int i = 0; i < sizeB; i++)
    {
        merged[sizeA + i] = B[i];
    }

    double result = func(merged, totalSize);

    delete[] merged;
    return result;
}

int main()
{
    int A[5] = { 3, 7, 1, 9, 4 };
    int B[4] = { 12, -2, 6, 8 };

    cout << "Array A: ";
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\nArray B: ";
    for (int i = 0; i < 4; i++)
    {
        cout << B[i] << " ";
    }
    cout << "\n\n";

    cout << "Choose operation:\n";
    cout << "1 - max\n";
    cout << "2 - min\n";
    cout << "3 - avg\n";
    cout << "Your choice: ";

    int choice;
    cin >> choice;

    double (*selectedFunc)(int[], int) = nullptr;

    if (choice == 1)
    {
        selectedFunc = findMax;
    }
    else if (choice == 2)
    {
        selectedFunc = findMin;
    }
    else if (choice == 3)
    {
        selectedFunc = findAvg;
    }
    else
    {
        cout << "Invalid choice!\n";
        return 0;
    }

    double result = Action(A, B, 5, 4, selectedFunc);
    cout << "Result: " << result << "\n";
}