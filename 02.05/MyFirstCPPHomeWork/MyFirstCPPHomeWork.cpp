#include <iostream>

using namespace std;

double salary(double sales)
{
    if (sales < 500)
        return 200 + sales * 0.03;
    else if (sales <= 1000)
        return 200 + sales * 0.05;
    else
        return 200 + sales * 0.08;
}

int main()
{
    // Task 1
    int num, maxNum;

    cout << "Enter 7 integers:\n";

    cin >> maxNum;

    for (int i = 1; i < 7; i++)
    {
        cin >> num;

        if (num > maxNum)
            maxNum = num;
    }

    cout << "Maximum number: " << maxNum << '\n';

    // Task 2
    double AB, BC;
    int weight;
    double fuelPerKm;

    cout << "Distance A-B: ";
    cin >> AB;

    cout << "Distance B-C: ";
    cin >> BC;

    cout << "Cargo weight (kg): ";
    cin >> weight;

    if (weight > 2000)
    {
        cout << "The plane cannot carry such a load!" << '\n';
    }
    else
    {
        if (weight <= 500)
            fuelPerKm = 1;
        else if (weight <= 1000)
            fuelPerKm = 4;
        else if (weight <= 1500)
            fuelPerKm = 7;
        else
            fuelPerKm = 9;

        double fuelAB = AB * fuelPerKm;
        double fuelBC = BC * fuelPerKm;

        if (fuelAB > 300 || fuelBC > 300)
        {
            cout << "Flight is impossible!" << '\n';
        }
        else
        {
            double refill = fuelBC;

            cout << "Minimum fuel needed for refueling at point B: "
                << refill << " liters" << '\n';
        }
    }

    cout << '\n';

    // Task 3
    double sales1, sales2, sales3;

    cout << "Sales of manager 1: ";
    cin >> sales1;

    cout << "Sales of manager 2: ";
    cin >> sales2;

    cout << "Sales of manager 3: ";
    cin >> sales3;

    double s1 = salary(sales1);
    double s2 = salary(sales2);
    double s3 = salary(sales3);

    int best = 1;
    double maxSalary = s1;

    if (s2 > maxSalary)
    {
        maxSalary = s2;
        best = 2;
    }

    if (s3 > maxSalary)
    {
        maxSalary = s3;
        best = 3;
    }

    maxSalary += 200;

    cout << "Salary of manager 1: " << s1 << "$" << '\n';
    cout << "Salary of manager 2: " << s2 << "$" << '\n';
    cout << "Salary of manager 3: " << s3 << "$" << '\n';

    cout << "Best manager: #" << best << '\n';
    cout << "Salary with bonus: " << maxSalary << "$" << '\n';

    cout << '\n';

    // Task 4
    int choice;

    cout << "1 - Calculate number of code lines" << '\n';
    cout << "2 - Calculate allowed number of late arrivals" << '\n';
    cout << "3 - Calculate salary" << '\n';

    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        double income;
        int late;

        cout << "Desired income: ";
        cin >> income;

        cout << "Number of late arrivals: ";
        cin >> late;

        double fines = (late / 3) * 20;
        double need = income + fines;

        int lines = (need * 100) / 50;

        cout << "You need to write "
            << lines << " lines of code" << '\n';
        break;
    }

    case 2:
    {
        int lines;
        double desiredSalary;

        cout << "Number of code lines: ";
        cin >> lines;

        cout << "Desired salary: ";
        cin >> desiredSalary;

        double earned = (lines / 100.0) * 50;

        if (desiredSalary > earned)
        {
            cout << "Such salary is impossible" << '\n';
        }
        else
        {
            int maxLate = ((earned - desiredSalary) / 20) * 3;

            cout << "Maximum number of late arrivals: "
                << maxLate << '\n';
        }
        break;
    }

    case 3:
    {
        int lines, late;

        cout << "Number of code lines: ";
        cin >> lines;

        cout << "Number of late arrivals: ";
        cin >> late;

        double money = (lines / 100.0) * 50;
        money -= (late / 3) * 20;

        if (money <= 0)
        {
            cout << "Vasya will not be paid" << '\n';
        }
        else
        {
            cout << "Vasya's salary: "
                << money << "$" << '\n';
        }
        break;
    }

    default:
        cout << "Invalid choice!" << '\n';
    }
}