#include <iostream>
#include <cstring>
using namespace std;

// TASK 1: remove a character at a given position
void removeChar(char chr[], int pos)
{
    int len = strlen(chr);
    if (pos < 0 || pos >= len)
    {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < len; i++)
    {
        chr[i] = chr[i + 1];
    }
}

// TASK 2: remove all occurrences of a character
void removeAllOccurrences(char chr[], char target)
{
    int j = 0;
    for (int i = 0; chr[i] != '\0'; i++)
    {
        if (chr[i] != target)
        {
            chr[j++] = chr[i];
        }
    }
    chr[j] = '\0';
}

// TASK 3: insert a character at a given position
void insertChar(char chr[], int pos, char ch, int bufferSize)
{
    int len = strlen(chr);
    if (pos < 0 || pos > len || len + 1 >= bufferSize)
    {
        cout << "Cannot insert character!\n";
        return;
    }
    for (int i = len; i >= pos; i--)
    {
        chr[i + 1] = chr[i];
    }
    chr[pos] = ch;
}

// TASK 4: replace all "." with "!"
void replaceDots(char chr[])
{
    for (int i = 0; chr[i] != '\0'; i++)
    {
        if (chr[i] == '.')
        {
            chr[i] = '!';
        }
    }
}

// TASK 5: count occurrences of a character
int countChar(const char chr[], char target)
{
    int count = 0;
    for (int i = 0; chr[i] != '\0'; i++)
    {
        if (chr[i] == target)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    // --- Task 1 ---
    char chr1[100] = "Hello, World!";
    removeChar(chr1, 5);
    cout << "Task 1: " << chr1 << "\n";

    // --- Task 2 ---
    char chr2[100] = "Programming in C++";
    removeAllOccurrences(chr2, 'g');
    cout << "Task 2: " << chr2 << "\n";

    // --- Task 3 ---
    char chr3[100] = "Hello World!";
    insertChar(chr3, 5, ',', 100);
    cout << "Task 3: " << chr3 << "\n";

    // --- Task 4 ---
    char chr4[200];
    cout << "Task 4, enter string: ";
    cin.getline(chr4, 200);
    replaceDots(chr4);
    cout << "Task 4, result: " << chr4 << "\n";

    // --- Task 5 ---
    char chr5[200];
    char target;
    cout << "Task 5, enter string: ";
    cin.getline(chr5, 200);
    cout << "Enter character to search: ";
    cin >> target;
    int count = countChar(chr5, target);
    cout << "Character '" << target << "' found " << count << " times.\n";
}