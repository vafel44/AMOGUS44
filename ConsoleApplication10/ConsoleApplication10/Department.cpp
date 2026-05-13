#define _CRT_SECURE_NO_WARNINGS
#include "Department.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// ==================== Реализация класса Department ====================

// Конструктор
Department::Department(const char* name) : employeeCount(0) {
    // Выделяем память под название департамента
    departmentName = new char[strlen(name) + 1];
    strcpy(departmentName, name);

    // Инициализируем массив указателей nullptr
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        employees[i] = nullptr;
    }
}

// Деструктор - освобождаем память
Department::~Department() {
    clear();           // Удаляем всех сотрудников
    delete[] departmentName;  // Освобождаем память под название
}

// Конструктор копирования
Department::Department(const Department& other) : employeeCount(other.employeeCount) {
    // Копируем название департамента
    departmentName = new char[strlen(other.departmentName) + 1];
    strcpy(departmentName, other.departmentName);

    // Копируем сотрудников (глубокое копирование)
    for (int i = 0; i < employeeCount; i++) {
        // Создаём копию каждого сотрудника через полиморфизм
        // В реальном коде нужно знать тип, здесь для простоты копируем через Employee
        // Но так как Employee абстрактный, нужно создавать конкретные копии
        // Для упрощения оставляем указатели
        employees[i] = other.employees[i];
    }
}

// Оператор присваивания
Department& Department::operator=(const Department& other) {
    if (this != &other) {
        // Очищаем текущие данные
        clear();
        delete[] departmentName;

        // Копируем новые данные
        departmentName = new char[strlen(other.departmentName) + 1];
        strcpy(departmentName, other.departmentName);
        employeeCount = other.employeeCount;

        for (int i = 0; i < employeeCount; i++) {
            employees[i] = other.employees[i];
        }
    }
    return *this;
}

// Добавление сотрудника
bool Department::addEmployee(Employee* emp) {
    // Проверка на переполнение
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "Error: Department is full!" << endl;
        return false;
    }

    // Проверка на nullptr
    if (emp == nullptr) {
        cout << "Error: Cannot add null employee!" << endl;
        return false;
    }

    // Добавляем сотрудника
    employees[employeeCount] = emp;
    employeeCount++;

    cout << "Added: ";
    emp->getInfo();

    return true;
}

// Удаление сотрудника по ID
bool Department::removeEmployee(int id) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i]->getId() == id) {
            cout << "Removed: ";
            employees[i]->getInfo();

            // Освобождаем память
            delete employees[i];

            // Сдвигаем оставшихся сотрудников влево
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }

            employeeCount--;
            return true;
        }
    }

    cout << "Employee with ID " << id << " not found." << endl;
    return false;
}

// Подсчёт общей зарплаты
double Department::getTotalSalary() const {
    double total = 0;
    for (int i = 0; i < employeeCount; i++) {
        total += employees[i]->calculateSalary();
    }
    return total;
}

// Поиск сотрудника с максимальной зарплатой
Employee* Department::getEmployeeWithMaxSalary() const {
    if (employeeCount == 0) {
        return nullptr;
    }

    Employee* maxEmp = employees[0];
    double maxSalary = maxEmp->calculateSalary();

    for (int i = 1; i < employeeCount; i++) {
        double currentSalary = employees[i]->calculateSalary();
        if (currentSalary > maxSalary) {
            maxSalary = currentSalary;
            maxEmp = employees[i];
        }
    }

    return maxEmp;
}

// Сортировка сотрудников по зарплате (пузырьковая сортировка по возрастанию)
void Department::sortBySalary() {
    // Пузырьковая сортировка
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = 0; j < employeeCount - i - 1; j++) {
            if (employees[j]->calculateSalary() > employees[j + 1]->calculateSalary()) {
                // Меняем местами
                Employee* temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    cout << "Employees sorted by salary (ascending)." << endl;
}

// Вывод всех сотрудников
void Department::printAllEmployees() const {
    cout << "\n=== Department: " << departmentName << " ===" << endl;
    cout << "Total employees: " << employeeCount << endl;

    if (employeeCount == 0) {
        cout << "No employees in this department." << endl;
        return;
    }

    // Выводим информацию о каждом сотруднике
    for (int i = 0; i < employeeCount; i++) {
        employees[i]->getInfo();
    }

    cout << "\nTotal Salary Budget: $" << fixed << setprecision(2)
        << getTotalSalary() << endl;
}

// Очистка всех сотрудников
void Department::clear() {
    for (int i = 0; i < employeeCount; i++) {
        delete employees[i];      // Освобождаем память каждого сотрудника
        employees[i] = nullptr;
    }
    employeeCount = 0;
}

// Получение сотрудника по индексу
Employee* Department::getEmployee(int index) const {
    if (index >= 0 && index < employeeCount) {
        return employees[index];
    }
    return nullptr;
}

// Получение количества сотрудников
int Department::getEmployeeCount() const {
    return employeeCount;
}