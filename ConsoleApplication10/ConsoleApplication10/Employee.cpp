#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include <iomanip>
#include <cstring>

// ==================== Реализация класса Employee ====================

// Конструктор с параметрами
Employee::Employee(const char* name, int id, double baseSalary)
    : id(id), baseSalary(baseSalary) {
    // Выделяем память под имя и копируем
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// Деструктор - освобождаем память
Employee::~Employee() {
    delete[] name;
}

// Конструктор копирования (глубокое копирование)
Employee::Employee(const Employee& other)
    : id(other.id), baseSalary(other.baseSalary) {
    // Выделяем новую память и копируем имя
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

// Оператор присваивания (глубокое копирование)
Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {  // Проверка на самоприсваивание
        // Освобождаем старую память
        delete[] name;

        // Копируем данные
        id = other.id;
        baseSalary = other.baseSalary;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    return *this;
}

// Расчёт зарплаты (базовая реализация)
double Employee::calculateSalary() const {
    return baseSalary;
}

// Вывод информации о сотруднике
void Employee::getInfo() const {
    cout << "ID: " << id << ", Name: " << name
        << ", Base Salary: $" << fixed << setprecision(2) << baseSalary;
}

// Геттер для имени
const char* Employee::getName() const {
    return name;
}

// Геттер для ID
int Employee::getId() const {
    return id;
}

// Геттер для базовой зарплаты
double Employee::getBaseSalary() const {
    return baseSalary;
}

// ==================== Реализация класса Manager ====================

// Конструктор Manager
Manager::Manager(const char* name, int id, double baseSalary,
    double bonusPercent, int subordinatesCount)
    : Employee(name, id, baseSalary),
    bonusPercent(bonusPercent),
    subordinatesCount(subordinatesCount) {
}

// Деструктор Manager
Manager::~Manager() {}

// Расчёт зарплаты менеджера: базовая + бонус + 100 за каждого подчинённого
double Manager::calculateSalary() const {
    double bonus = (bonusPercent / 100.0) * baseSalary;
    return baseSalary + bonus + (subordinatesCount * 100.0);
}

// Вывод информации о менеджере
void Manager::getInfo() const {
    Employee::getInfo();
    cout << ", Role: Manager, Bonus: " << bonusPercent
        << "%, Subordinates: " << subordinatesCount
        << ", Total Salary: $" << fixed << setprecision(2)
        << calculateSalary() << endl;
}

// ==================== Реализация класса Developer ====================

// Конструктор Developer
Developer::Developer(const char* name, int id, double baseSalary,
    const char* programmingLanguage, int experienceYears)
    : Employee(name, id, baseSalary), experienceYears(experienceYears) {
    // Выделяем память под язык программирования
    this->programmingLanguage = new char[strlen(programmingLanguage) + 1];
    strcpy(this->programmingLanguage, programmingLanguage);
}

// Деструктор Developer - освобождаем память
Developer::~Developer() {
    delete[] programmingLanguage;
}

// Конструктор копирования Developer
Developer::Developer(const Developer& other)
    : Employee(other), experienceYears(other.experienceYears) {
    programmingLanguage = new char[strlen(other.programmingLanguage) + 1];
    strcpy(programmingLanguage, other.programmingLanguage);
}

// Оператор присваивания Developer
Developer& Developer::operator=(const Developer& other) {
    if (this != &other) {
        // Вызываем оператор присваивания базового класса
        Employee::operator=(other);

        // Освобождаем старую память
        delete[] programmingLanguage;

        // Копируем новые данные
        experienceYears = other.experienceYears;
        programmingLanguage = new char[strlen(other.programmingLanguage) + 1];
        strcpy(programmingLanguage, other.programmingLanguage);
    }
    return *this;
}

// Расчёт зарплаты разработчика: базовая + опыт * 5000
double Developer::calculateSalary() const {
    return baseSalary + (experienceYears * 5000.0);
}

// Вывод информации о разработчике
void Developer::getInfo() const {
    Employee::getInfo();
    cout << ", Role: Developer, Language: " << programmingLanguage
        << ", Experience: " << experienceYears << " years"
        << ", Total Salary: $" << fixed << setprecision(2)
        << calculateSalary() << endl;
}

// ==================== Реализация класса Intern ====================

// Конструктор Intern
Intern::Intern(const char* name, int id, double baseSalary, bool hasMentor)
    : Employee(name, id, baseSalary), hasMentor(hasMentor) {
}

// Деструктор Intern
Intern::~Intern() {}

// Расчёт зарплаты стажёра: 70% от базовой
double Intern::calculateSalary() const {
    return baseSalary * 0.7;
}

// Вывод информации о стажёре
void Intern::getInfo() const {
    Employee::getInfo();
    cout << ", Role: Intern, Has Mentor: " << (hasMentor ? "Yes" : "No")
        << ", Total Salary: $" << fixed << setprecision(2)
        << calculateSalary() << endl;
}