#include <iostream>

using namespace std;

// 1
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// 2
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 3
#define SQUARE(a) ((a) * (a))

// 4
#define POWER(a, n) ([](double x, int p) { \
    double result = 1; \
    for (int i = 0; i < p; i++) \
        result *= x; \
    return result; \
}(a, n))

// 5
#define EVEN(a) ((a) % 2 == 0)

// 6
#define ODD(a) ((a) % 2 != 0)

int main()
{
    double a, b;
    int n;

    // 1
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Smaller: " << MIN(a, b) << endl;

    // 2
    cout << "Larger: " << MAX(a, b) << endl;

    // 3
    cout << "Enter number for square: ";
    cin >> a;

    cout << "Square: " << SQUARE(a) << endl;

    // 4
    cout << "Enter number: ";
    cin >> a;

    cout << "Enter power: ";
    cin >> n;

    cout << "Result: " << POWER(a, n) << endl;

    // 5
    int number;

    cout << "Enter integer number: ";
    cin >> number;

    if (EVEN(number))
        cout << "Number is even" << endl;
    else
        cout << "Number is not even" << endl;

    // 6
    if (ODD(number))
        cout << "Number is odd" << endl;
    else
        cout << "Number is not odd" << endl;

}