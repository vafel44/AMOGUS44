#define _CRT_SECURE_NO_WARNINGS
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Employee.h"

// Максимальное количество сотрудников в департаменте
const int MAX_EMPLOYEES = 100;

class Department {
private:
    char* departmentName;                 // Название департамента
    Employee* employees[MAX_EMPLOYEES];   // Массив указателей на сотрудников
    int employeeCount;                    // Текущее количество сотрудников

public:
    // Конструктор
    Department(const char* name);

    // Деструктор
    ~Department();

    // Конструктор копирования
    Department(const Department& other);

    // Оператор присваивания
    Department& operator=(const Department& other);

    // Добавление сотрудника
    bool addEmployee(Employee* emp);

    // Удаление сотрудника по ID
    bool removeEmployee(int id);

    // Подсчёт общей зарплаты всех сотрудников
    double getTotalSalary() const;

    // Поиск сотрудника с максимальной зарплатой
    Employee* getEmployeeWithMaxSalary() const;

    // Сортировка сотрудников по зарплате (пузырьковая сортировка)
    void sortBySalary();

    // Вывод всех сотрудников
    void printAllEmployees() const;

    // Очистка всех сотрудников
    void clear();

    // Поиск сотрудника по индексу
    Employee* getEmployee(int index) const;

    // Получение количества сотрудников
    int getEmployeeCount() const;
};

#endif