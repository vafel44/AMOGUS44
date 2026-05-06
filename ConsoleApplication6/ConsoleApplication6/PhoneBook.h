#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

class Abonent {
    char* fullName;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* additionalInfo;

public:
    Abonent();
    Abonent(const char* name, const char* home, const char* work, const char* mobile, const char* info);
    Abonent(const Abonent& other);
    ~Abonent();

    inline const char* getFullName() const { return fullName; }

    void display() const;
    void setFullName(const char* name);
};

class PhoneBook {
    Abonent** abonents;
    int count;
    int capacity;
    void resize();

public:
    PhoneBook();
    ~PhoneBook();

    void addAbonent();
    void removeAbonent();
    void searchAbonent();
    void showAll();
};

#endif