#include <iostream>

using namespace std;

int main()
{
    // Task 1
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minVal)
            minVal = arr[i];

        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    cout << "Min: " << minVal << '\n';
    cout << "Max: " << maxVal << '\n';

    cout << '\n';

    // Task 2
    int profit[12];

    cout << "Enter profit for 12 months:\n";

    for (int i = 0; i < 12; i++)
        cin >> profit[i];

    int l, r;

    cout << "Enter range (1-12): ";
    cin >> l >> r;

    if (l > r)
    {
        int temp = l;
        l = r;
        r = temp;
    }

    int minMonth = l, maxMonth = l;

    for (int i = l; i <= r; i++)
    {
        if (profit[i - 1] < profit[minMonth - 1])
            minMonth = i;

        if (profit[i - 1] > profit[maxMonth - 1])
            maxMonth = i;
    }

    cout << "Min month: " << minMonth << '\n';
    cout << "Max month: " << maxMonth << '\n';

    cout << '\n';

    // Task 3
    int N;

    cout << "Enter N: ";
    cin >> N;

    double arr2[100];

    cout << "Enter elements:\n";

    for (int i = 0; i < N; i++)
        cin >> arr2[i];

    double sumNeg = 0;
    double prodBetween = 1;
    double prodEvenIndex = 1;
    double sumBetweenNeg = 0;

    int minIndex = 0, maxIndex = 0;

    for (int i = 0; i < N; i++)
    {
        if (arr2[i] < 0)
            sumNeg += arr2[i];

        if (arr2[i] < arr2[minIndex])
            minIndex = i;

        if (arr2[i] > arr2[maxIndex])
            maxIndex = i;
    }

    if (minIndex > maxIndex)
    {
        int t = minIndex;
        minIndex = maxIndex;
        maxIndex = t;
    }

    for (int i = minIndex + 1; i < maxIndex; i++)
        prodBetween *= arr2[i];

    for (int i = 0; i < N; i += 2)
        prodEvenIndex *= arr2[i];

    int firstNeg = -1, lastNeg = -1;

    for (int i = 0; i < N; i++)
    {
        if (arr2[i] < 0)
        {
            if (firstNeg == -1)
                firstNeg = i;

            lastNeg = i;
        }
    }

    if (firstNeg != -1 && lastNeg != -1 && firstNeg < lastNeg)
    {
        for (int i = firstNeg + 1; i < lastNeg; i++)
            sumBetweenNeg += arr2[i];
    }

    cout << "Sum of negative elements: " << sumNeg << '\n';
    cout << "Product between min and max: " << prodBetween << '\n';
    cout << "Product of even index elements: " << prodEvenIndex << '\n';
    cout << "Sum between first and last negative: " << sumBetweenNeg << '\n';

    cout << '\n';

    // Task 4
    int a[10];
    int b[5], c[5];

    cout << "Enter 10 elements:\n";

    for (int i = 0; i < 10; i++)
        cin >> a[i];

    for (int i = 0; i < 5; i++)
    {
        b[i] = a[i];
        c[i] = a[i + 5];
    }

    cout << "First array:\n";

    for (int i = 0; i < 5; i++)
        cout << b[i] << '\n';

    cout << "Second array:\n";

    for (int i = 0; i < 5; i++)
        cout << c[i] << '\n';

    cout << '\n';

    // Task 5
    int x[5], y[5], z[5];

    cout << "Enter first array:\n";

    for (int i = 0; i < 5; i++)
        cin >> x[i];

    cout << "Enter second array:\n";

    for (int i = 0; i < 5; i++)
        cin >> y[i];

    for (int i = 0; i < 5; i++)
        z[i] = x[i] + y[i];

    cout << "Result:\n";

    for (int i = 0; i < 5; i++)
        cout << z[i] << '\n';

}