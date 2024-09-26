#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;       // Employee's name
    long employeeNumber; // Employee number

public:
    // Function to get data from the user
    void getData() {
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee number: ";
        cin >> employeeNumber;
    }

    // Function to display employee data
    void putData() const {
        cout << "Name: " << name << ", Employee Number: " << employeeNumber << endl;
    }
};

int main() {
    const int MAX_EMPLOYEES = 100; // Maximum number of employees
    Employee employees[MAX_EMPLOYEES]; // Array of employees
    int count = 0; // Number of employees entered

    char moreData;
    do {
        if (count < MAX_EMPLOYEES) {
            employees[count].getData(); // Get data for each employee
            count++;
        } else {
            cout << "Maximum number of employees reached." << endl;
            break;
        }

        cout << "Do you want to enter another employee? (y/n): ";
        cin >> moreData;

    } while (moreData == 'y' || moreData == 'Y');

    // Print all employee data
    cout << "\nEmployee Data:\n";
    for (int i = 0; i < count; i++) {
        employees[i].putData(); // Display data for each employee
    }

    return 0;
}
