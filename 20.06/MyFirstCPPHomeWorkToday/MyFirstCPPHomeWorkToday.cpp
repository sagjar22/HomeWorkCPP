#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// 1
struct Complex
{
    double real;
    double imag;
};

Complex add(Complex a, Complex b)
{
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

Complex sub(Complex a, Complex b)
{
    Complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

Complex mul(Complex a, Complex b)
{
    Complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

Complex divi(Complex a, Complex b)
{
    Complex c;
    double d = b.real * b.real + b.imag * b.imag;

    c.real = (a.real * b.real + a.imag * b.imag) / d;
    c.imag = (a.imag * b.real - a.real * b.imag) / d;

    return c;
}

void printComplex(Complex a)
{
    cout << a.real;

    if (a.imag >= 0)
        cout << " + " << a.imag << "i";
    else
        cout << " - " << -a.imag << "i";

    cout << endl;
}


// 2
struct Car
{
    double length;
    double clearance;
    double engineVolume;
    double power;
    double wheelDiameter;
    char color[30];
    char gearbox[30];
};

void setCar(Car& car)
{
    cout << "Length: ";
    cin >> car.length;

    cout << "Clearance: ";
    cin >> car.clearance;

    cout << "Engine volume: ";
    cin >> car.engineVolume;

    cout << "Power: ";
    cin >> car.power;

    cout << "Wheel diameter: ";
    cin >> car.wheelDiameter;

    cout << "Color: ";
    cin >> car.color;

    cout << "Gearbox: ";
    cin >> car.gearbox;
}

void printCar(Car car)
{
    cout << "Length: " << car.length << endl;
    cout << "Clearance: " << car.clearance << endl;
    cout << "Engine volume: " << car.engineVolume << endl;
    cout << "Power: " << car.power << endl;
    cout << "Wheel diameter: " << car.wheelDiameter << endl;
    cout << "Color: " << car.color << endl;
    cout << "Gearbox: " << car.gearbox << endl;
}

void searchCar(Car car)
{
    char color[30];

    cout << "Enter color to search: ";
    cin >> color;

    if (strcmp(car.color, color) == 0)
        cout << "Car found" << endl;
    else
        cout << "Car not found" << endl;
}


// 3
struct Book
{
    char title[100];
    char author[100];
    char publisher[100];
    char genre[50];
};

void printBook(Book book)
{
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Publisher: " << book.publisher << endl;
    cout << "Genre: " << book.genre << endl;
}

void editBook(Book& book)
{
    cout << "Enter title: ";
    cin >> book.title;

    cout << "Enter author: ";
    cin >> book.author;

    cout << "Enter publisher: ";
    cin >> book.publisher;

    cout << "Enter genre: ";
    cin >> book.genre;
}

void printBooks(Book books[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nBook " << i + 1 << endl;
        printBook(books[i]);
    }
}

void searchAuthor(Book books[], int n)
{
    char author[100];

    cout << "Enter author: ";
    cin >> author;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(books[i].author, author) == 0)
        {
            printBook(books[i]);
        }
    }
}

void searchTitle(Book books[], int n)
{
    char title[100];

    cout << "Enter title: ";
    cin >> title;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(books[i].title, title) == 0)
        {
            printBook(books[i]);
        }
    }
}

void sortByTitle(Book books[], int n)
{
    Book temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(books[i].title, books[j].title) > 0)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void sortByAuthor(Book books[], int n)
{
    Book temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(books[i].author, books[j].author) > 0)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void sortByPublisher(Book books[], int n)
{
    Book temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(books[i].publisher, books[j].publisher) > 0)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}


// 4
struct Machine
{
    char color[30];
    char model[30];
    char number[9];
};

void setMachine(Machine& m)
{
    cout << "Color: ";
    cin >> m.color;

    cout << "Model: ";
    cin >> m.model;

    cout << "Number: ";
    cin >> m.number;
}

void printMachine(Machine m)
{
    cout << "Color: " << m.color << endl;
    cout << "Model: " << m.model << endl;
    cout << "Number: " << m.number << endl;
}

void editMachine(Machine& m)
{
    setMachine(m);
}

void printMachines(Machine machines[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nMachine " << i + 1 << endl;
        printMachine(machines[i]);
    }
}

void searchMachine(Machine machines[], int n)
{
    char number[9];

    cout << "Enter number: ";
    cin >> number;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(machines[i].number, number) == 0)
        {
            printMachine(machines[i]);
        }
    }
}


// 5
struct Living
{
    double speed;
    char type[20];
    char color[30];

    double flightSpeed;
    bool hoofed;
    int iq;
};

void inputLiving(Living& x)
{
    cout << "Speed: ";
    cin >> x.speed;

    cout << "Type (bird/cattle/human): ";
    cin >> x.type;

    cout << "Color: ";
    cin >> x.color;

    if (strcmp(x.type, "bird") == 0)
    {
        cout << "Flight speed: ";
        cin >> x.flightSpeed;
    }
    else if (strcmp(x.type, "cattle") == 0)
    {
        cout << "Hoofed (1/0): ";
        cin >> x.hoofed;
    }
    else if (strcmp(x.type, "human") == 0)
    {
        cout << "IQ: ";
        cin >> x.iq;
    }
}

void printLiving(Living x)
{
    cout << "Speed: " << x.speed << endl;
    cout << "Type: " << x.type << endl;
    cout << "Color: " << x.color << endl;

    if (strcmp(x.type, "bird") == 0)
    {
        cout << "Flight speed: " << x.flightSpeed << endl;
    }
    else if (strcmp(x.type, "cattle") == 0)
    {
        cout << "Hoofed: " << x.hoofed << endl;
    }
    else if (strcmp(x.type, "human") == 0)
    {
        cout << "IQ: " << x.iq << endl;
    }
}

void editLiving(Living& x)
{
    inputLiving(x);
}

void printLivingList(Living arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nLiving " << i + 1 << endl;
        printLiving(arr[i]);
    }
}

void searchLiving(Living arr[], int n)
{
    char type[20];

    cout << "Enter type: ";
    cin >> type;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i].type, type) == 0)
        {
            printLiving(arr[i]);
        }
    }
}


// 6
struct Student
{
    char surname[50];
    char group[20];
    int marks[5];
};

void inputStudent(Student& s)
{
    cout << "Surname: ";
    cin >> s.surname;

    cout << "Group: ";
    cin >> s.group;

    cout << "Enter 5 marks: ";

    for (int i = 0; i < 5; i++)
    {
        cin >> s.marks[i];
    }
}

void printStudent(Student s)
{
    cout << s.surname << " ";
    cout << s.group << " ";

    for (int i = 0; i < 5; i++)
    {
        cout << s.marks[i] << " ";
    }

    cout << endl;
}

bool excellent(Student s)
{
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        if (s.marks[i] == 5)
            count++;
    }

    return count > 3;
}

bool badStudent(Student s)
{
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        if (s.marks[i] == 2 || s.marks[i] == 3)
            count++;
    }

    return count > 2;
}

void changeStudentArray(Student*& students, int oldSize, int newSize)
{
    Student* temp = new Student[newSize];

    int size = oldSize;

    if (newSize < oldSize)
        size = newSize;

    for (int i = 0; i < size; i++)
    {
        temp[i] = students[i];
    }

    delete[] students;
    students = temp;
}


// 7
struct Date
{
    int day;
    int month;
    int year;
};

struct Man
{
    char surname[50];
    char name[50];
    int age;
    Date birthday;
};

void inputMan(Man& m)
{
    cout << "Surname: ";
    cin >> m.surname;

    cout << "Name: ";
    cin >> m.name;

    cout << "Age: ";
    cin >> m.age;

    cout << "Birthday day: ";
    cin >> m.birthday.day;

    cout << "Birthday month: ";
    cin >> m.birthday.month;

    cout << "Birthday year: ";
    cin >> m.birthday.year;
}

void printMan(Man m)
{
    cout << m.surname << " ";
    cout << m.name << " ";
    cout << m.age << " ";

    cout << m.birthday.day << ".";
    cout << m.birthday.month << ".";
    cout << m.birthday.year << endl;
}

void sortBySurname(Man arr[], int n)
{
    Man temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i].surname, arr[j].surname) > 0)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortByName(Man arr[], int n)
{
    Man temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i].name, arr[j].name) > 0)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void birthdayMonth(Man arr[], int n)
{
    int month;

    cout << "Enter month: ";
    cin >> month;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].birthday.month == month)
        {
            cout << arr[i].name << " "
                << arr[i].surname << " - "
                << arr[i].birthday.day << "."
                << arr[i].birthday.month << "."
                << arr[i].birthday.year << endl;
        }
    }
}

void searchMan(Man arr[], int n)
{
    char surname[50];
    char name[50];

    cout << "Enter surname: ";
    cin >> surname;

    cout << "Enter name: ";
    cin >> name;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i].surname, surname) == 0 &&
            strcmp(arr[i].name, name) == 0)
        {
            printMan(arr[i]);
        }
    }
}

void editMan(Man& m)
{
    inputMan(m);
}


// 8
int main()
{
    cout << "Program with 7 tasks" << endl;

    // 1
    cout << "\nTASK 1" << endl;

    Complex a, b;

    cout << "Enter first complex number (real imag): ";
    cin >> a.real >> a.imag;

    cout << "Enter second complex number (real imag): ";
    cin >> b.real >> b.imag;

    cout << "Sum: ";
    printComplex(add(a, b));

    cout << "Difference: ";
    printComplex(sub(a, b));

    cout << "Multiplication: ";
    printComplex(mul(a, b));

    if (b.real != 0 || b.imag != 0)
    {
        cout << "Division: ";
        printComplex(divi(a, b));
    }
    else
    {
        cout << "Division is impossible" << endl;
    }


    // 2
    cout << "\nTASK 2" << endl;

    Car car;

    setCar(car);

    cout << "\nCar information:" << endl;
    printCar(car);

    searchCar(car);


    // 3
    cout << "\nTASK 3" << endl;

    Book books[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "\nEnter book " << i + 1 << endl;
        editBook(books[i]);
    }

    cout << "\nAll books:" << endl;
    printBooks(books, 10);

    int bookNumber;

    cout << "\nEnter book number to edit: ";
    cin >> bookNumber;

    if (bookNumber >= 1 && bookNumber <= 10)
    {
        editBook(books[bookNumber - 1]);
    }

    cout << "\nSearch by author:" << endl;
    searchAuthor(books, 10);

    cout << "\nSearch by title:" << endl;
    searchTitle(books, 10);

    sortByTitle(books, 10);
    cout << "\nSorted by title:" << endl;
    printBooks(books, 10);

    sortByAuthor(books, 10);
    cout << "\nSorted by author:" << endl;
    printBooks(books, 10);

    sortByPublisher(books, 10);
    cout << "\nSorted by publisher:" << endl;
    printBooks(books, 10);


    // 4
    cout << "\nTASK 4" << endl;

    Machine machine;

    setMachine(machine);

    cout << "\nMachine:" << endl;
    printMachine(machine);

    Machine machines[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "\nEnter machine " << i + 1 << endl;
        setMachine(machines[i]);
    }

    int machineNumber;

    cout << "\nEnter machine number to edit: ";
    cin >> machineNumber;

    if (machineNumber >= 1 && machineNumber <= 10)
    {
        editMachine(machines[machineNumber - 1]);
    }

    cout << "\nAll machines:" << endl;
    printMachines(machines, 10);

    searchMachine(machines, 10);


    // 5
    cout << "\nTASK 5" << endl;

    Living living;

    inputLiving(living);

    cout << "\nLiving information:" << endl;
    printLiving(living);

    Living livingList[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "\nEnter living " << i + 1 << endl;
        inputLiving(livingList[i]);
    }

    int livingNumber;

    cout << "\nEnter number to edit: ";
    cin >> livingNumber;

    if (livingNumber >= 1 && livingNumber <= 10)
    {
        editLiving(livingList[livingNumber - 1]);
    }

    cout << "\nAll living:" << endl;
    printLivingList(livingList, 10);

    searchLiving(livingList, 10);


    // 6
    cout << "\nTASK 6" << endl;

    int studentCount;

    cout << "Enter number of students: ";
    cin >> studentCount;

    Student* students = new Student[studentCount];

    for (int i = 0; i < studentCount; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        inputStudent(students[i]);
    }

    cout << "\nAll students:" << endl;

    for (int i = 0; i < studentCount; i++)
    {
        printStudent(students[i]);
    }

    cout << "\nExcellent students:" << endl;

    for (int i = 0; i < studentCount; i++)
    {
        if (excellent(students[i]))
        {
            printStudent(students[i]);
        }
    }

    cout << "\nBad students:" << endl;

    for (int i = 0; i < studentCount; i++)
    {
        if (badStudent(students[i]))
        {
            printStudent(students[i]);
        }
    }

    int newStudentCount;

    cout << "\nEnter new number of students: ";
    cin >> newStudentCount;

    changeStudentArray(students, studentCount, newStudentCount);
    studentCount = newStudentCount;

    for (int i = 0; i < studentCount; i++)
    {
        if (i >= studentCount)
            break;
    }

    delete[] students;


    // 7
    cout << "\nTASK 7" << endl;

    int manCount;

    cout << "Enter number of people: ";
    cin >> manCount;

    Man* men = new Man[manCount];

    for (int i = 0; i < manCount; i++)
    {
        cout << "\nPerson " << i + 1 << endl;
        inputMan(men[i]);
    }

    cout << "\nPeople:" << endl;

    for (int i = 0; i < manCount; i++)
    {
        printMan(men[i]);
    }

    sortBySurname(men, manCount);

    cout << "\nSorted by surname:" << endl;

    for (int i = 0; i < manCount; i++)
    {
        printMan(men[i]);
    }

    sortByName(men, manCount);

    cout << "\nSorted by name:" << endl;

    for (int i = 0; i < manCount; i++)
    {
        printMan(men[i]);
    }

    cout << "\nBirthday search:" << endl;
    birthdayMonth(men, manCount);

    cout << "\nSearch person:" << endl;
    searchMan(men, manCount);

    int editNumber;

    cout << "\nEnter person number to edit: ";
    cin >> editNumber;

    if (editNumber >= 1 && editNumber <= manCount)
    {
        editMan(men[editNumber - 1]);
    }

    cout << "\nAfter editing:" << endl;

    for (int i = 0; i < manCount; i++)
    {
        printMan(men[i]);
    }

    int newManCount;

    cout << "\nEnter new number of people: ";
    cin >> newManCount;

    Man* newMen = new Man[newManCount];

    int copyCount = manCount;

    if (newManCount < manCount)
        copyCount = newManCount;

    for (int i = 0; i < copyCount; i++)
    {
        newMen[i] = men[i];
    }

    delete[] men;
    men = newMen;
    manCount = newManCount;

    cout << "\nArray size changed." << endl;

    delete[] men;
}