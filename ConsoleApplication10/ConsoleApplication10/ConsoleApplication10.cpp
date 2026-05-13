#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include "Department.h"
#include <iostream>

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "=== Testing Employee Hierarchy ===" << endl;
    cout << "========================================\n" << endl;

    // ========== Создание сотрудников ==========
    cout << "--- Creating Employees ---" << endl;

    // Создаём менеджеров
    Manager* m1 = new Manager("Alice Johnson", 1001, 50000, 15, 5);
    Manager* m2 = new Manager("Bob Smith", 1002, 55000, 20, 8);

    // Создаём разработчиков
    Developer* d1 = new Developer("Charlie Brown", 2001, 45000, "C++", 5);
    Developer* d2 = new Developer("Diana Prince", 2002, 48000, "Python", 3);
    Developer* d3 = new Developer("Eve Wilson", 2003, 42000, "Java", 2);

    // Создаём стажёров
    Intern* i1 = new Intern("Frank Miller", 3001, 30000, true);
    Intern* i2 = new Intern("Grace Lee", 3002, 28000, false);

    cout << "\n";

    // ========== Создание департамента ==========
    Department dept("Software Engineering");

    // ========== Добавление сотрудников ==========
    cout << "--- Adding Employees to Department ---" << endl;
    dept.addEmployee(m1);
    dept.addEmployee(m2);
    dept.addEmployee(d1);
    dept.addEmployee(d2);
    dept.addEmployee(d3);
    dept.addEmployee(i1);
    dept.addEmployee(i2);

    // ========== Вывод всех сотрудников ==========
    dept.printAllEmployees();

    // ========== Поиск сотрудника с максимальной зарплатой ==========
    cout << "\n--- Employee with Maximum Salary ---" << endl;
    Employee* maxEmp = dept.getEmployeeWithMaxSalary();
    if (maxEmp != nullptr) {
        cout << "Employee with highest salary: ";
        maxEmp->getInfo();
    }

    // ========== Сортировка по зарплате ==========
    cout << "\n--- Sorting Employees by Salary ---" << endl;
    dept.sortBySalary();
    dept.printAllEmployees();

    // ========== Удаление сотрудника ==========
    cout << "\n--- Removing Employee ---" << endl;
    dept.removeEmployee(2002);  // Удаляем Diana Prince

    // Вывод после удаления
    dept.printAllEmployees();

    // ========== Проверка полиморфизма ==========
    cout << "\n--- Polymorphism Test (Base pointer to Derived) ---" << endl;
    // Базовый указатель указывает на объект производного класса
    Employee* empPtr = new Developer("Test Dev", 9999, 40000, "C#", 4);

    // Вызов виртуальных методов через базовый указатель
    cout << "Calling calculateSalary() via base pointer: $"
        << empPtr->calculateSalary() << endl;
    empPtr->getInfo();

    // Освобождаем память
    delete empPtr;

    // ========== Демонстрация очистки департамента ==========
    cout << "\n--- Cleaning up department ---" << endl;
    dept.clear();
    dept.printAllEmployees();

    // ========== Дополнительная проверка: создание сотрудников в цикле ==========
    cout << "\n--- Additional Test: Adding employees after clear ---" << endl;
    dept.addEmployee(new Developer("New Dev", 4001, 35000, "JavaScript", 1));
    dept.addEmployee(new Intern("New Intern", 4002, 25000, true));
    dept.printAllEmployees();

    cout << "\n========================================" << endl;
    cout << "=== Program Finished Successfully ===" << endl;
    cout << "========================================" << endl;

    return 0;
}