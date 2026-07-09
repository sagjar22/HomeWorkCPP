#include <iostream>
#include <cstring>
using namespace std;

// TASK 1: count letters, digits and other characters in a string
void countChars(const char chr[], int& letters, int& digits, int& others)
{
    letters = 0;
    digits = 0;
    others = 0;
    for (int i = 0; chr[i] != '\0'; i++)
    {
        char c = chr[i];
        if (c >= 48 && c <= 57)
        {
            digits++;
        }
        else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            letters++;
        }
        else
        {
            others++;
        }
    }
}

// TASK 2: compare two strings
int mystrcmp(const char* str1, const char* str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return (str1[i] > str2[i]) ? 1 : -1;
        }
        i++;
    }
    if (str1[i] == str2[i])
    {
        return 0;
    }
    return (str1[i] != '\0') ? 1 : -1;
}

// TASK 2: convert string to number
int StringToNumber(char* str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            break;
        }
        result = result * 10 + (str[i] - '0');
    }

    return result * sign;
}

// TASK 2: convert number to string
char* NumberToString(int number)
{
    bool negative = number < 0;
    if (negative)
    {
        number = -number;
    }

    char temp[20];
    int i = 0;

    if (number == 0)
    {
        temp[i++] = '0';
    }

    while (number > 0)
    {
        temp[i++] = (number % 10) + '0';
        number /= 10;
    }

    if (negative)
    {
        temp[i++] = '-';
    }

    char* result = new char[i + 1];
    for (int j = 0; j < i; j++)
    {
        result[j] = temp[i - 1 - j];
    }
    result[i] = '\0';

    return result;
}

// TASK 2: convert string to uppercase
char* Uppercase(char* str1)
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z')
        {
            str1[i] = str1[i] - 'a' + 'A';
        }
    }
    return str1;
}

// TASK 2: convert string to lowercase
char* Lowercase(char* str1)
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] >= 'A' && str1[i] <= 'Z')
        {
            str1[i] = str1[i] - 'A' + 'a';
        }
    }
    return str1;
}

// TASK 2: reverse a string
char* mystrrev(char* str)
{
    int len = strlen(str);
    char* result = new char[len + 1];

    for (int i = 0; i < len; i++)
    {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';

    return result;
}

int main()
{
    // --- Task 1 ---
    char chr1[200];
    cout << "Task 1, enter string: ";
    cin.getline(chr1, 200);

    int letters, digits, others;
    countChars(chr1, letters, digits, others);
    cout << "Letters: " << letters << "\n";
    cout << "Digits: " << digits << "\n";
    cout << "Others: " << others << "\n";

    // --- Task 2: mystrcmp ---
    char s1[] = "apple";
    char s2[] = "banana";
    cout << "\nmystrcmp(\"apple\", \"banana\") = " << mystrcmp(s1, s2) << "\n";
    cout << "mystrcmp(\"apple\", \"apple\") = " << mystrcmp(s1, "apple") << "\n";

    // --- Task 2: StringToNumber ---
    char numStr[] = "-2456";
    cout << "StringToNumber(\"-2456\") = " << StringToNumber(numStr) << "\n";

    // --- Task 2: NumberToString ---
    char* converted = NumberToString(-2456);
    cout << "NumberToString(-2456) = " << converted << "\n";
    delete[] converted;

    // --- Task 2: Uppercase / Lowercase ---
    char s3[] = "Hello World!";
    cout << "Uppercase: " << Uppercase(s3) << "\n";
    char s4[] = "Hello World!";
    cout << "Lowercase: " << Lowercase(s4) << "\n";

    // --- Task 2: mystrrev ---
    char s5[] = "Hello";
    char* reversed = mystrrev(s5);
    cout << "Reversed: " << reversed << "\n";
    delete[] reversed;
}