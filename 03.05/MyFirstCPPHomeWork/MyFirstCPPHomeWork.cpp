#include <iostream>

using namespace std;

int main()
{
    // Task 1
    int a;

    cout << "Enter a: ";
    cin >> a;

    int sum = 0;

    for (int i = a; i <= 500; i++)
        sum += i;

    cout << "Sum from a to 500: " << sum << '\n';

    cout << '\n';

    // Task 2
    int x, y;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter y: ";
    cin >> y;

    int power = 1;

    for (int i = 0; i < y; i++)
        power *= x;

    cout << "x^y = " << power << '\n';

    cout << '\n';

    // Task 3
    double sum1000 = 0;

    for (int i = 1; i <= 1000; i++)
        sum1000 += i;

    double avg = sum1000 / 1000;

    cout << "Average from 1 to 1000: " << avg << '\n';

    cout << '\n';

    // Task 4
    int a2;

    cout << "Enter a (1-20): ";
    cin >> a2;

    int product = 1;

    for (int i = a2; i <= 20; i++)
        product *= i;

    cout << "Product from a to 20: " << product << '\n';

    cout << '\n';

    // Task 5
    int k;

    cout << "Enter k: ";
    cin >> k;

    for (int i = 1; i <= 10; i++)
        cout << k << " x " << i << " = " << k * i << '\n';

    cout << '\n';

    // Task 6
    int A;

    cout << "Enter A: ";
    cin >> A;

    for (int B = 1; B * B <= A; B++)
    {
        if (A % (B * B) == 0 && A % (B * B * B) != 0)
            cout << B << '\n';
    }

    cout << '\n';

    // Task 7
    int num;

    cout << "Enter a number: ";
    cin >> num;

    for (int i = 1; i <= num; i++)
        if (num % i == 0)
            cout << i << '\n';

    cout << '\n';

    // Task 8
    int a3, b3;

    cout << "Enter two numbers: ";
    cin >> a3 >> b3;

    int limit;
    if (a3 < b3)
        limit = a3;
    else
        limit = b3;

    for (int i = 1; i <= limit; i++)
        if (a3 % i == 0 && b3 % i == 0)
            cout << i << '\n';

    cout << '\n';

    // Task 9
    char ch;
    int choice, h;

    cout << "Enter symbol: ";
    cin >> ch;

    cout << "1 - square\n2 - rectangle\n3 - triangle\n";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter side: ";
        cin >> h;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < h; j++)
                cout << ch;
            cout << '\n';
        }
    }
    else if (choice == 2)
    {
        int w;

        cout << "Enter height: ";
        cin >> h;

        cout << "Enter width: ";
        cin >> w;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
                cout << ch;
            cout << '\n';
        }
    }
    else if (choice == 3)
    {
        cout << "Enter height: ";
        cin >> h;

        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= i; j++)
                cout << ch;
            cout << '\n';
        }
    }
    else
    {
        cout << "Invalid choice" << '\n';
    }
}