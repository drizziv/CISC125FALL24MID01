#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Employee {
protected:
    string name;
    int empID;
public:
    Employee(const string &empName, int id) : name(empName), empID(id) {} // the part after the : is called the member initializer list, name(emName) initializes name to the value of empName, and empID to id

    virtual void printDetails() const = 0; // Pure virtual function
    virtual double calculateSalary() const = 0; // Pure virtual function
    virtual ~Employee() {} // Virtual destructor to prevent memory leak
};

// Derived Class for Full-Time Employee
class FullTimeEmployee : public Employee {
private:
    double basicSalary;
public:
    FullTimeEmployee(const string &empName, int id, double salary)// constructor
        : Employee(empName, id), basicSalary(salary) {}

    void printDetails() const override { // function inherited from base class
        cout << "Full-Time Employee\n";
        cout << "Name: " << name << ", ID: " << empID << endl;
        cout << "Basic Salary: " << basicSalary << endl;
    }

    double calculateSalary() const override { // Method to return the basic salary of the employee
        return basicSalary;
    }
};

// Derived Class for Part-Time Employee
class PartTimeEmployee : public Employee {
private:
    double hourlyWage; // private variables of part time employee
    int hoursWorked;
public:
    PartTimeEmployee(const string &empName, int id, double wage, int hours) // constructor of part time employee
        : Employee(empName, id), hourlyWage(wage), hoursWorked(hours) {}

    void printDetails() const override { // method of the derrived function
        cout << "Part-Time Employee\n";
        cout << "Name: " << name << ", ID: " << empID << endl;
        cout << "Hourly Wage: " << hourlyWage << ", Hours Worked: " << hoursWorked << endl;
    }

    double calculateSalary() const override {
        return hourlyWage * hoursWorked; // returns the salary of the worker
    }
};

int main() {
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    // Pointer array to hold Employee objects
    Employee* employees[numEmployees];

    for (int i = 0; i < numEmployees; i++) { // for loop to get employee details and create objects based on employee type
        string name;
        int id, type;
        cout << "\nEnter details for employee " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> name;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Employee Type (1 for Full-Time, 2 for Part-Time): ";
        cin >> type;

        if (type == 1) {  // For full-time employees, get salary and create a FullTimeEmployee object
            double salary;
            cout << "Enter basic salary: ";
            cin >> salary;
            employees[i] = new FullTimeEmployee(name, id, salary);
        } else if (type == 2) { // For part-time employees, get hourly wage and hours worked, then create a PartTimeEmployee object
            double wage;
            int hours;
            cout << "Enter hourly wage: ";
            cin >> wage;
            cout << "Enter hours worked: ";
            cin >> hours;
            employees[i] = new PartTimeEmployee(name, id, wage, hours);
        } else {
            cout << "Invalid type. Please restart the program.\n";
            return 1;
        }
    }
 // Loop to display details and salaries of all employees
    cout << "\nEmployee Details and Salaries:\n";
    for (int i = 0; i < numEmployees; i++) {
        employees[i]->printDetails();
        cout << "Salary: " << employees[i]->calculateSalary() << endl;
        
    }

    // Freeing dynamically allocated memory
    for (int i = 0; i < numEmployees; i++) {
        delete employees[i];
    }

    return 0;
}
