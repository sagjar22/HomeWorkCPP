#include <iostream>

using namespace std;

// 1
char* toBinary(int number)
{
    static char result[33];
    int i = 0;

    if (number == 0)
    {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    while (number > 0)
    {
        result[i] = (number % 2) + '0';
        number = number / 2;
        i++;
    }

    result[i] = '\0';

    for (int j = 0; j < i / 2; j++)
    {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    return result;
}

// 2
char* toHex(int number)
{
    static char result[20];

    char symbols[] = "0123456789ABCDEF";

    int i = 0;

    if (number == 0)
    {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    while (number > 0)
    {
        result[i] = symbols[number % 16];
        number = number / 16;
        i++;
    }

    result[i] = '\0';

    for (int j = 0; j < i / 2; j++)
    {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    return result;
}

// 3
int binaryToDecimal(char* binary)
{
    int result = 0;

    for (int i = 0; binary[i] != '\0'; i++)
    {
        result = result * 2 + (binary[i] - '0');
    }

    return result;
}

// 4
int hexToDecimal(char* hex)
{
    int result = 0;

    for (int i = 0; hex[i] != '\0'; i++)
    {
        int value;

        if (hex[i] >= '0' && hex[i] <= '9')
        {
            value = hex[i] - '0';
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            value = hex[i] - 'A' + 10;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            value = hex[i] - 'a' + 10;
        }
        else
        {
            return -1;
        }

        result = result * 16 + value;
    }

    return result;
}

int main()
{
    int number;

    // 1
    cout << "Enter decimal number: ";
    cin >> number;

    cout << "Binary: " << toBinary(number) << endl;

    // 2
    cout << "Hexadecimal: " << toHex(number) << endl;

    // 3
    char binary[100];

    cout << "Enter binary number: ";
    cin >> binary;

    cout << "Decimal: " << binaryToDecimal(binary) << endl;

    // 4
    char hex[100];

    cout << "Enter hexadecimal number: ";
    cin >> hex;

    cout << "Decimal: " << hexToDecimal(hex) << endl;

}