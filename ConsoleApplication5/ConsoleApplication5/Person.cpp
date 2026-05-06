#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <cstring>

// ============ DATE ============
Date::Date(int d, int m, int y) : day(d), month(m), year(y) 
{

}
Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int y) { year = y; }

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::display() const {
    std::cout << day << "." << month << "." << year;
}

// ============ PERSON ============
int Person::instanceCount = 0;

// Конструктор с параметрами
Person::Person(int id, const char* last, const char* first, const char* pat, const Date& date)
    : id(id), birthDate(date) {
    lastName = new char[strlen(last) + 1];
    firstName = new char[strlen(first) + 1];
    patronymic = new char[strlen(pat) + 1];
    strcpy(lastName, last);
    strcpy(firstName, first);
    strcpy(patronymic, pat);
    instanceCount++;
}

// Конструктор по умолчанию (делегирование)
Person::Person() : Person(0, "Иванов", "Иван", "Иванович", Date(1, 1, 2000)) {}

// Конструктор копирования
Person::Person(const Person& other) : id(other.id), birthDate(other.birthDate) {
    lastName = new char[strlen(other.lastName) + 1];
    firstName = new char[strlen(other.firstName) + 1];
    patronymic = new char[strlen(other.patronymic) + 1];
    strcpy(lastName, other.lastName);
    strcpy(firstName, other.firstName);
    strcpy(patronymic, other.patronymic);
    instanceCount++;
}

// Деструктор
Person::~Person() {
    delete[] lastName;
    delete[] firstName;
    delete[] patronymic;
    instanceCount--;
}

// Статическая функция
int Person::getInstanceCount() {
    return instanceCount;
}

// Сеттеры
void Person::setId(int newId) { id = newId; }

void Person::setLastName(const char* newLastName) {
    delete[] lastName;
    lastName = new char[strlen(newLastName) + 1];
    strcpy(lastName, newLastName);
}

void Person::setFirstName(const char* newFirstName) {
    delete[] firstName;
    firstName = new char[strlen(newFirstName) + 1];
    strcpy(firstName, newFirstName);
}

void Person::setPatronymic(const char* newPatronymic) {
    delete[] patronymic;
    patronymic = new char[strlen(newPatronymic) + 1];
    strcpy(patronymic, newPatronymic);
}

void Person::setBirthDate(const Date& date) { birthDate = date; }

// Геттеры
int Person::getId() const { return id; }
const char* Person::getLastName() const { return lastName; }
const char* Person::getFirstName() const { return firstName; }
const char* Person::getPatronymic() const { return patronymic; }
Date Person::getBirthDate() const { return birthDate; }

// Вывод
void Person::display() const {
    std::cout << "ID: " << id << ", ФИО: " << lastName << " " << firstName << " " << patronymic << ", Дата: ";
    birthDate.display();
    std::cout << std::endl;
}