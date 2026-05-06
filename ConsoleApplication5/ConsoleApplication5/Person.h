#ifndef PERSON_H
#define PERSON_H

#include <iostream>

// Класс Дата
class Date {
    int day, month, year;
public:
    Date(int d = 1, int m = 1, int y = 2000);
    Date(const Date& other);

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void display() const;
};

// Класс Человек
class Person {
private:
    int id;
    char* lastName;
    char* firstName;
    char* patronymic;
    Date birthDate;
    static int instanceCount;

public:
    // Конструкторы
    Person(int id, const char* last, const char* first, const char* pat, const Date& date);
    Person();  // Делегирование конструктора
    Person(const Person& other);

    // Деструктор
    ~Person();

    // Статическая функция подсчета
    static int getInstanceCount();

    // Сеттеры и геттеры
    void setId(int newId);
    void setLastName(const char* newLastName);
    void setFirstName(const char* newFirstName);
    void setPatronymic(const char* newPatronymic);
    void setBirthDate(const Date& date);

    int getId() const;
    const char* getLastName() const;
    const char* getFirstName() const;
    const char* getPatronymic() const;
    Date getBirthDate() const;

    // Вывод
    void display() const;
};

#endif