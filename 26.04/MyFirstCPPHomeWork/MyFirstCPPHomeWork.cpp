#include <iostream>

using namespace std;

int main()
{
    // Task 1
    int totalSeconds;

    cout << "Enter time in seconds: ";
    cin >> totalSeconds;

    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    cout << hours << " hours "
        << minutes << " minutes "
        << seconds << " seconds" << '\n';

    cout << '\n';

    // Task 2
    double money;

    cout << "Enter amount of money: ";
    cin >> money;

    int hryvnias = (int)money;
    int kopecks = (money - hryvnias) * 100;

    cout << hryvnias << " UAH "
        << kopecks << " kopecks" << '\n';

    cout << '\n';

    // Task 3
    double distance;
    int min, sec;

    cout << "Running speed calculation" << '\n';

    cout << "Enter distance (meters): ";
    cin >> distance;

    cout << "Enter minutes: ";
    cin >> min;

    cout << "Enter seconds: ";
    cin >> sec;

    int totalTime = min * 60 + sec;

    double speed = (distance / totalTime) * 3.6;

    cout << "Distance: " << distance << " m" << '\n';
    cout << "Time: " << min << " min "
        << sec << " sec = "
        << totalTime << " sec" << '\n';

    cout << "Speed: " << speed
        << " km/h" << '\n';

    cout << '\n';

    // Task 4
    int days;

    cout << "Enter number of days: ";
    cin >> days;

    int weeks = days / 7;
    int remainingDays = days % 7;

    cout << weeks << " weeks "
        << remainingDays << " days" << '\n';

    cout << '\n';

    // Task 5
    double airportDistance;
    double travelTime;

    cout << "Enter distance to airport (km): ";
    cin >> airportDistance;

    cout << "Enter travel time (hours): ";
    cin >> travelTime;

    double requiredSpeed = airportDistance / travelTime;

    cout << "Required speed: "
        << requiredSpeed
        << " km/h" << '\n';

    cout << '\n';

    // Task 6
    double tripDistance;
    double fuelConsumption;
    double price1, price2, price3;

    cout << "Enter distance (km): ";
    cin >> tripDistance;

    cout << "Enter fuel consumption per 100 km: ";
    cin >> fuelConsumption;

    cout << "Enter price of fuel 1: ";
    cin >> price1;

    cout << "Enter price of fuel 2: ";
    cin >> price2;

    cout << "Enter price of fuel 3: ";
    cin >> price3;

    double fuelNeeded = tripDistance * fuelConsumption / 100;

    cout << "Fuel 1 cost: "
        << fuelNeeded * price1 << '\n';

    cout << "Fuel 2 cost: "
        << fuelNeeded * price2 << '\n';

    cout << "Fuel 3 cost: "
        << fuelNeeded * price3 << '\n';

    cout << '\n';

    // Task 7
    int daySeconds;

    cout << "Enter seconds since start of day: ";
    cin >> daySeconds;

    int h = daySeconds / 3600;
    int m = (daySeconds % 3600) / 60;
    int s = daySeconds % 60;

    cout << "Current time: "
        << h << ":"
        << m << ":"
        << s << '\n';

    int leftSeconds = 86400 - daySeconds;

    int leftHours = leftSeconds / 3600;
    int leftMinutes = (leftSeconds % 3600) / 60;
    int leftSecs = leftSeconds % 60;

    cout << "Until midnight: "
        << leftHours << " hours "
        << leftMinutes << " minutes "
        << leftSecs << " seconds" << '\n';

    cout << '\n';

    // Task 8
    int workSeconds;

    cout << "Enter seconds since start of work day: ";
    cin >> workSeconds;

    int workHoursLeft = (28800 - workSeconds) / 3600;

    if (workHoursLeft < 0)
        workHoursLeft = 0;

    cout << "Hours left at work: "
        << workHoursLeft << '\n';
}