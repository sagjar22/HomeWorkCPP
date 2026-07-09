#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

// ================= shared matrix helpers =================
int** createMatrix(int rows, int cols)
{
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void fillMatrixRandom(int** matrix, int rows, int cols, int minVal, int maxVal)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
        }
    }
}

void printMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

// TASK 1: insert a column into a 2D array at a given position
int** insertColumn(int** matrix, int rows, int cols, int pos, int colValues[])
{
    int** result = createMatrix(rows, cols + 1);
    for (int i = 0; i < rows; i++)
    {
        int srcCol = 0;
        for (int j = 0; j < cols + 1; j++)
        {
            if (j == pos)
            {
                result[i][j] = colValues[i];
            }
            else
            {
                result[i][j] = matrix[i][srcCol];
                srcCol++;
            }
        }
    }
    return result;
}

// TASK 2: remove a column from a 2D array by index
int** removeColumn(int** matrix, int rows, int cols, int pos)
{
    int** result = createMatrix(rows, cols - 1);
    for (int i = 0; i < rows; i++)
    {
        int destCol = 0;
        for (int j = 0; j < cols; j++)
        {
            if (j != pos)
            {
                result[i][destCol] = matrix[i][j];
                destCol++;
            }
        }
    }
    return result;
}

// TASK 3: cyclic shift of rows / columns
void shiftRows(int** matrix, int rows, int cols, int times, bool down)
{
    times = times % rows;
    for (int t = 0; t < times; t++)
    {
        if (down)
        {
            int* lastRow = matrix[rows - 1];
            for (int i = rows - 1; i > 0; i--)
            {
                matrix[i] = matrix[i - 1];
            }
            matrix[0] = lastRow;
        }
        else
        {
            int* firstRow = matrix[0];
            for (int i = 0; i < rows - 1; i++)
            {
                matrix[i] = matrix[i + 1];
            }
            matrix[rows - 1] = firstRow;
        }
    }
}

void shiftCols(int** matrix, int rows, int cols, int times, bool right)
{
    times = times % cols;
    for (int t = 0; t < times; t++)
    {
        if (right)
        {
            for (int i = 0; i < rows; i++)
            {
                int last = matrix[i][cols - 1];
                for (int j = cols - 1; j > 0; j--)
                {
                    matrix[i][j] = matrix[i][j - 1];
                }
                matrix[i][0] = last;
            }
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {
                int first = matrix[i][0];
                for (int j = 0; j < cols - 1; j++)
                {
                    matrix[i][j] = matrix[i][j + 1];
                }
                matrix[i][cols - 1] = first;
            }
        }
    }
}

// TASK 4: transpose a matrix
int** transpose(int** matrix, int rows, int cols)
{
    int** result = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

// TASK 5: dynamic contact book (name + phone)
struct Contact
{
    char* name;
    char* phone;
};

Contact* createContactArray(int capacity)
{
    return new Contact[capacity];
}

void addContact(Contact* contacts, int& count, const char* name, const char* phone)
{
    contacts[count].name = new char[strlen(name) + 1];
    strcpy(contacts[count].name, name);
    contacts[count].phone = new char[strlen(phone) + 1];
    strcpy(contacts[count].phone, phone);
    count++;
}

int searchByName(Contact* contacts, int count, const char* name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(contacts[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int searchByPhone(Contact* contacts, int count, const char* phone)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(contacts[i].phone, phone) == 0)
        {
            return i;
        }
    }
    return -1;
}

void editContact(Contact* contacts, int index, const char* newName, const char* newPhone)
{
    delete[] contacts[index].name;
    delete[] contacts[index].phone;
    contacts[index].name = new char[strlen(newName) + 1];
    strcpy(contacts[index].name, newName);
    contacts[index].phone = new char[strlen(newPhone) + 1];
    strcpy(contacts[index].phone, newPhone);
}

void freeContacts(Contact* contacts, int count)
{
    for (int i = 0; i < count; i++)
    {
        delete[] contacts[i].name;
        delete[] contacts[i].phone;
    }
    delete[] contacts;
}

// TASK 6: sort 5 surnames ascending
void sortSurnames(char surnames[][50], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(surnames[j], surnames[j + 1]) > 0)
            {
                char temp[50];
                strcpy(temp, surnames[j]);
                strcpy(surnames[j], surnames[j + 1]);
                strcpy(surnames[j + 1], temp);
            }
        }
    }
}

// TASK 7: set operations on three matrices A, B, C
void flatten(int** matrix, int rows, int cols, int result[], int& size)
{
    size = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[size++] = matrix[i][j];
        }
    }
}

bool contains(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return true;
        }
    }
    return false;
}

int findCommonAll(int a[], int sa, int b[], int sb, int c[], int sc, int result[])
{
    int count = 0;
    for (int i = 0; i < sa; i++)
    {
        if (contains(b, sb, a[i]) && contains(c, sc, a[i]) && !contains(result, count, a[i]))
        {
            result[count++] = a[i];
        }
    }
    return count;
}

int findUnique(int a[], int sa, int b[], int sb, int c[], int sc, int result[])
{
    int count = 0;
    for (int i = 0; i < sa; i++)
    {
        if (!contains(b, sb, a[i]) && !contains(c, sc, a[i]) && !contains(result, count, a[i]))
        {
            result[count++] = a[i];
        }
    }
    for (int i = 0; i < sb; i++)
    {
        if (!contains(a, sa, b[i]) && !contains(c, sc, b[i]) && !contains(result, count, b[i]))
        {
            result[count++] = b[i];
        }
    }
    for (int i = 0; i < sc; i++)
    {
        if (!contains(a, sa, c[i]) && !contains(b, sb, c[i]) && !contains(result, count, c[i]))
        {
            result[count++] = c[i];
        }
    }
    return count;
}

int findCommonAC(int a[], int sa, int c[], int sc, int result[])
{
    int count = 0;
    for (int i = 0; i < sa; i++)
    {
        if (contains(c, sc, a[i]) && !contains(result, count, a[i]))
        {
            result[count++] = a[i];
        }
    }
    return count;
}

int findNegatives(int a[], int sa, int b[], int sb, int c[], int sc, int result[])
{
    int count = 0;
    for (int i = 0; i < sa; i++)
    {
        if (a[i] < 0 && !contains(result, count, a[i]))
        {
            result[count++] = a[i];
        }
    }
    for (int i = 0; i < sb; i++)
    {
        if (b[i] < 0 && !contains(result, count, b[i]))
        {
            result[count++] = b[i];
        }
    }
    for (int i = 0; i < sc; i++)
    {
        if (c[i] < 0 && !contains(result, count, c[i]))
        {
            result[count++] = c[i];
        }
    }
    return count;
}

int main()
{
    srand(time(0));

    // --- Task 1: insert column ---
    int rows1 = 3, cols1 = 3;
    int** m1 = createMatrix(rows1, cols1);
    int initVals1[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            m1[i][j] = initVals1[i][j];
        }
    }
    cout << "Task 1 - original matrix:\n";
    printMatrix(m1, rows1, cols1);
    int newCol[3] = { 100, 200, 300 };
    int** m1new = insertColumn(m1, rows1, cols1, 1, newCol);
    cols1++;
    cout << "Task 1 - after inserting column at position 1:\n";
    printMatrix(m1new, rows1, cols1);
    freeMatrix(m1, rows1);
    freeMatrix(m1new, rows1);

    // --- Task 2: remove column ---
    int rows2 = 3, cols2 = 4;
    int** m2 = createMatrix(rows2, cols2);
    int initVals2[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            m2[i][j] = initVals2[i][j];
        }
    }
    cout << "\nTask 2 - original matrix:\n";
    printMatrix(m2, rows2, cols2);
    int** m2new = removeColumn(m2, rows2, cols2, 2);
    cols2--;
    cout << "Task 2 - after removing column 2:\n";
    printMatrix(m2new, rows2, cols2);
    freeMatrix(m2, rows2);
    freeMatrix(m2new, rows2);

    // --- Task 3: cyclic shift ---
    int rows3 = 3, cols3 = 3;
    int** m3 = createMatrix(rows3, cols3);
    int initVals3[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    for (int i = 0; i < rows3; i++)
    {
        for (int j = 0; j < cols3; j++)
        {
            m3[i][j] = initVals3[i][j];
        }
    }
    cout << "\nTask 3 - original matrix:\n";
    printMatrix(m3, rows3, cols3);
    shiftRows(m3, rows3, cols3, 1, true);
    cout << "Task 3 - after shifting rows down by 1:\n";
    printMatrix(m3, rows3, cols3);
    shiftCols(m3, rows3, cols3, 1, true);
    cout << "Task 3 - after shifting columns right by 1:\n";
    printMatrix(m3, rows3, cols3);
    freeMatrix(m3, rows3);

    // --- Task 4: transpose ---
    int rows4 = 2, cols4 = 3;
    int** m4 = createMatrix(rows4, cols4);
    int initVals4[2][3] = { {1,2,3},{4,5,6} };
    for (int i = 0; i < rows4; i++)
    {
        for (int j = 0; j < cols4; j++)
        {
            m4[i][j] = initVals4[i][j];
        }
    }
    cout << "\nTask 4 - original matrix:\n";
    printMatrix(m4, rows4, cols4);
    int** m4t = transpose(m4, rows4, cols4);
    cout << "Task 4 - transposed matrix:\n";
    printMatrix(m4t, cols4, rows4);
    freeMatrix(m4, rows4);
    freeMatrix(m4t, cols4);

    // --- Task 5: contact book ---
    int capacity5 = 10;
    int count5 = 0;
    Contact* contacts = createContactArray(capacity5);
    addContact(contacts, count5, "Ivan Petrenko", "0991112233");
    addContact(contacts, count5, "Olena Kovalenko", "0997778899");

    cout << "\nTask 5 - contact list:\n";
    for (int i = 0; i < count5; i++)
    {
        cout << contacts[i].name << " - " << contacts[i].phone << "\n";
    }

    int foundIndex = searchByName(contacts, count5, "Olena Kovalenko");
    if (foundIndex != -1)
    {
        cout << "Found by name: " << contacts[foundIndex].phone << "\n";
    }

    foundIndex = searchByPhone(contacts, count5, "0991112233");
    if (foundIndex != -1)
    {
        cout << "Found by phone: " << contacts[foundIndex].name << "\n";
    }

    editContact(contacts, 0, "Ivan Petrenko", "0991110000");
    cout << "After editing: " << contacts[0].name << " - " << contacts[0].phone << "\n";

    freeContacts(contacts, count5);

    // --- Task 6: sort surnames ---
    char surnames[5][50];
    cout << "\nTask 6 - enter 5 surnames:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Surname " << i + 1 << ": ";
        cin >> surnames[i];
    }
    sortSurnames(surnames, 5);
    cout << "Sorted surnames:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << surnames[i] << "\n";
    }

    // --- Task 7: A, B, C set operations ---
    int rowsA, colsA, rowsB, colsB, rowsC, colsC;

    cout << "\nTask 7 - enter size of matrix A (rows cols): ";
    cin >> rowsA >> colsA;
    int** A = createMatrix(rowsA, colsA);
    fillMatrixRandom(A, rowsA, colsA, -10, 10);
    cout << "Matrix A:\n";
    printMatrix(A, rowsA, colsA);

    cout << "Enter size of matrix B (rows cols): ";
    cin >> rowsB >> colsB;
    int** B = createMatrix(rowsB, colsB);
    fillMatrixRandom(B, rowsB, colsB, -10, 10);
    cout << "Matrix B:\n";
    printMatrix(B, rowsB, colsB);

    cout << "Enter size of matrix C (rows cols): ";
    cin >> rowsC >> colsC;
    int** C = createMatrix(rowsC, colsC);
    fillMatrixRandom(C, rowsC, colsC, -10, 10);
    cout << "Matrix C:\n";
    printMatrix(C, rowsC, colsC);

    int flatA[100], flatB[100], flatC[100];
    int sizeA, sizeB, sizeC;
    flatten(A, rowsA, colsA, flatA, sizeA);
    flatten(B, rowsB, colsB, flatB, sizeB);
    flatten(C, rowsC, colsC, flatC, sizeC);

    int commonAll[100];
    int commonAllCount = findCommonAll(flatA, sizeA, flatB, sizeB, flatC, sizeC, commonAll);
    cout << "\nCommon values in A, B and C: ";
    for (int i = 0; i < commonAllCount; i++)
    {
        cout << commonAll[i] << " ";
    }
    cout << "\n";

    int uniqueVals[300];
    int uniqueCount = findUnique(flatA, sizeA, flatB, sizeB, flatC, sizeC, uniqueVals);
    cout << "Unique values (in only one of A, B, C): ";
    for (int i = 0; i < uniqueCount; i++)
    {
        cout << uniqueVals[i] << " ";
    }
    cout << "\n";

    int commonAC[100];
    int commonACCount = findCommonAC(flatA, sizeA, flatC, sizeC, commonAC);
    cout << "Common values in A and C: ";
    for (int i = 0; i < commonACCount; i++)
    {
        cout << commonAC[i] << " ";
    }
    cout << "\n";

    int negatives[300];
    int negativesCount = findNegatives(flatA, sizeA, flatB, sizeB, flatC, sizeC, negatives);
    cout << "Negative values from A, B, C (no duplicates): ";
    for (int i = 0; i < negativesCount; i++)
    {
        cout << negatives[i] << " ";
    }
    cout << "\n";

    freeMatrix(A, rowsA);
    freeMatrix(B, rowsB);
    freeMatrix(C, rowsC);
}