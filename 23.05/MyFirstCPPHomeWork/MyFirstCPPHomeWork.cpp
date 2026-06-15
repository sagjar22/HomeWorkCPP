#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//1

const int matrixSize = 3;

void initMatrix(int matrix[][matrixSize]) {
    cout << "Enter " << matrixSize * matrixSize << " integer values:\n";
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
            cin >> matrix[i][j];
}

void initMatrix(double matrix[][matrixSize]) {
    cout << "Enter " << matrixSize * matrixSize << " double values:\n";
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
            cin >> matrix[i][j];
}

void initMatrix(char matrix[][matrixSize]) {
    cout << "Enter " << matrixSize * matrixSize << " char values:\n";
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
            cin >> matrix[i][j];
}

void printMatrix(int matrix[][matrixSize]) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++)
            cout << matrix[i][j] << "\t";
        cout << "\n";
    }
}

void printMatrix(double matrix[][matrixSize]) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++)
            cout << matrix[i][j] << "\t";
        cout << "\n";
    }
}

void printMatrix(char matrix[][matrixSize]) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++)
            cout << matrix[i][j] << "\t";
        cout << "\n";
    }
}

void diagMinMax(int matrix[][matrixSize]) {
    int minVal = matrix[0][0];
    int maxVal = matrix[0][0];

    for (int i = 1; i < matrixSize; i++) {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }

    cout << "Int diagonal min: " << minVal << ", max: " << maxVal << "\n";
}

void diagMinMax(double matrix[][matrixSize]) {
    double minVal = matrix[0][0];
    double maxVal = matrix[0][0];

    for (int i = 1; i < matrixSize; i++) {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }

    cout << "Double diagonal min: " << minVal << ", max: " << maxVal << "\n";
}

void diagMinMax(char matrix[][matrixSize]) {
    char minVal = matrix[0][0];
    char maxVal = matrix[0][0];

    for (int i = 1; i < matrixSize; i++) {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }

    cout << "Char diagonal min: " << minVal << ", max: " << maxVal << "\n";
}

void sortRows(int matrix[][matrixSize]) {
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize - 1; j++)
            for (int k = 0; k < matrixSize - j - 1; k++)
                if (matrix[i][k] > matrix[i][k + 1])
                    swap(matrix[i][k], matrix[i][k + 1]);
}

void sortRows(double matrix[][matrixSize]) {
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize - 1; j++)
            for (int k = 0; k < matrixSize - j - 1; k++)
                if (matrix[i][k] > matrix[i][k + 1])
                    swap(matrix[i][k], matrix[i][k + 1]);
}

void sortRows(char matrix[][matrixSize]) {
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize - 1; j++)
            for (int k = 0; k < matrixSize - j - 1; k++)
                if (matrix[i][k] > matrix[i][k + 1])
                    swap(matrix[i][k], matrix[i][k + 1]);
}


//2

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


//3

int generateSecret() {
    srand(time(NULL));
    int secret;

    do {
        secret = 1000 + rand() % 9000;
    } while (
        (secret / 1000) == ((secret / 100) % 10) ||
        (secret / 1000) == ((secret / 10) % 10) ||
        (secret / 1000) == (secret % 10) ||
        ((secret / 100) % 10) == ((secret / 10) % 10) ||
        ((secret / 100) % 10) == (secret % 10) ||
        ((secret / 10) % 10) == (secret % 10)
        );

    return secret;
}

void countBullsCows(int secret, int guess, int& bulls, int& cows) {
    bulls = 0;
    cows = 0;

    int secretDigits[4], guessDigits[4];

    for (int i = 3; i >= 0; i--) {
        secretDigits[i] = secret % 10;
        guessDigits[i] = guess % 10;
        secret /= 10;
        guess /= 10;
    }

    for (int i = 0; i < 4; i++) {
        if (secretDigits[i] == guessDigits[i]) {
            bulls++;
        }
        else {
            for (int j = 0; j < 4; j++) {
                if (i != j && guessDigits[i] == secretDigits[j] && guessDigits[j] != secretDigits[j]) {
                    cows++;
                    break;
                }
            }
        }
    }
}

int playGame(int secret, int attempts) {
    int guess;
    cout << "Enter your guess (4-digit number with unique digits): ";
    cin >> guess;

    int bulls, cows;
    countBullsCows(secret, guess, bulls, cows);

    cout << "Bulls (right digit, right place): " << bulls << "\n";
    cout << "Cows (right digit, wrong place): " << cows << "\n";

    if (bulls == 4) {
        cout << "You guessed it! Attempts: " << attempts + 1 << "\n";
        return attempts + 1;
    }

    return playGame(secret, attempts + 1);
}


int main() {
    // Task 1 - demonstration
    cout << "=== Task 1: Overloaded Matrix Functions ===\n";

    int iMatrix[matrixSize][matrixSize];
    double dMatrix[matrixSize][matrixSize];
    char cMatrix[matrixSize][matrixSize];

    initMatrix(iMatrix);
    cout << "Int matrix:\n";
    printMatrix(iMatrix);
    diagMinMax(iMatrix);
    sortRows(iMatrix);
    cout << "After row sort:\n";
    printMatrix(iMatrix);

    initMatrix(dMatrix);
    cout << "Double matrix:\n";
    printMatrix(dMatrix);
    diagMinMax(dMatrix);
    sortRows(dMatrix);
    cout << "After row sort:\n";
    printMatrix(dMatrix);

    initMatrix(cMatrix);
    cout << "Char matrix:\n";
    printMatrix(cMatrix);
    diagMinMax(cMatrix);
    sortRows(cMatrix);
    cout << "After row sort:\n";
    printMatrix(cMatrix);


    // Task 2 - demonstration
    cout << "\n=== Task 2: Recursive GCD ===\n";

    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << "\n";


    // Task 3 - demonstration
    cout << "\n=== Task 3: Bulls and Cows ===\n";

    int secret = generateSecret();
    playGame(secret, 0);
}