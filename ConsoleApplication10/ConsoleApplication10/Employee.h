#define _CRT_SECURE_NO_WARNINGS
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Базовый класс Employee (Сотрудник)
class Employee {
protected:
    char* name;           // Имя сотрудника (динамическая память)
    int id;               // Уникальный идентификатор
    double baseSalary;    // Базовая зарплата

public:
    // Конструктор с параметрами
    Employee(const char* name, int id, double baseSalary);

    // Виртуальный деструктор (для правильного удаления производных объектов)
    virtual ~Employee();

    // Конструктор копирования (глубокое копирование)
    Employee(const Employee& other);

    // Оператор присваивания (глубокое копирование)
    Employee& operator=(const Employee& other);

    // Виртуальные методы (будут переопределены в производных классах)
    virtual double calculateSalary() const;
    virtual void getInfo() const;

    // Геттеры
    const char* getName() const;
    int getId() const;
    double getBaseSalary() const;
};

// Класс Manager (Менеджер) - добавляет бонус и подчинённых
class Manager : public Employee {
private:
    double bonusPercent;      // Бонус в процентах
    int subordinatesCount;    // Количество подчинённых

public:
    // Конструктор
    Manager(const char* name, int id, double baseSalary,
        double bonusPercent, int subordinatesCount);

    // Деструктор
    ~Manager();

    // Переопределение методов
    double calculateSalary() const override;
    void getInfo() const override;
};

// Класс Developer (Разработчик) - добавляет язык и опыт
class Developer : public Employee {
private:
    char* programmingLanguage;    // Язык программирования (динамическая память)
    int experienceYears;          // Опыт в годах

public:
    // Конструктор
    Developer(const char* name, int id, double baseSalary,
        const char* programmingLanguage, int experienceYears);

    // Деструктор
    ~Developer();

    // Конструктор копирования
    Developer(const Developer& other);

    // Оператор присваивания
    Developer& operator=(const Developer& other);

    // Переопределение методов
    double calculateSalary() const override;
    void getInfo() const override;
};

// Класс Intern (Стажёр) - добавляет наличие наставника
class Intern : public Employee {
private:
    bool hasMentor;    // Наличие наставника

public:
    // Конструктор
    Intern(const char* name, int id, double baseSalary, bool hasMentor);

    // Деструктор
    ~Intern();

    // Переопределение методов
    double calculateSalary() const override;
    void getInfo() const override;
};

#endif