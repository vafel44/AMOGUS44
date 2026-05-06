#define _CRT_SECURE_NO_WARNINGS
#include "PhoneBook.h"
#include <cstring>
#include <windows.h>

// ============ ABONENT ============
Abonent::Abonent() {
    fullName = new char[20];
    homePhone = new char[20];
    workPhone = new char[20];
    mobilePhone = new char[20];
    additionalInfo = new char[50];

    strcpy(fullName, "Neizvestny");
    strcpy(homePhone, "000");
    strcpy(workPhone, "000");
    strcpy(mobilePhone, "000");
    strcpy(additionalInfo, "Net dannyh");
}

Abonent::Abonent(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
    fullName = new char[strlen(name) + 1];
    homePhone = new char[strlen(home) + 1];
    workPhone = new char[strlen(work) + 1];
    mobilePhone = new char[strlen(mobile) + 1];
    additionalInfo = new char[strlen(info) + 1];

    strcpy(fullName, name);
    strcpy(homePhone, home);
    strcpy(workPhone, work);
    strcpy(mobilePhone, mobile);
    strcpy(additionalInfo, info);
}

Abonent::Abonent(const Abonent& other) {
    fullName = new char[strlen(other.fullName) + 1];
    homePhone = new char[strlen(other.homePhone) + 1];
    workPhone = new char[strlen(other.workPhone) + 1];
    mobilePhone = new char[strlen(other.mobilePhone) + 1];
    additionalInfo = new char[strlen(other.additionalInfo) + 1];

    strcpy(fullName, other.fullName);
    strcpy(homePhone, other.homePhone);
    strcpy(workPhone, other.workPhone);
    strcpy(mobilePhone, other.mobilePhone);
    strcpy(additionalInfo, other.additionalInfo);
}

Abonent::~Abonent() {
    delete[] fullName;
    delete[] homePhone;
    delete[] workPhone;
    delete[] mobilePhone;
    delete[] additionalInfo;
}

void Abonent::setFullName(const char* name) {
    delete[] fullName;
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
}

void Abonent::display() const {
    std::cout << "\nFIO: " << fullName << std::endl;
    std::cout << "Tel: " << homePhone << " | " << workPhone << " | " << mobilePhone << std::endl;
    std::cout << "Info: " << additionalInfo << std::endl;
}

// ============ PHONEBOOK ============
PhoneBook::PhoneBook() : count(0), capacity(10) {
    abonents = new Abonent * [capacity];
}

PhoneBook::~PhoneBook() {
    for (int i = 0; i < count; i++) delete abonents[i];
    delete[] abonents;
}

void PhoneBook::resize() {
    capacity *= 2;
    Abonent** newAbonents = new Abonent * [capacity];
    for (int i = 0; i < count; i++) newAbonents[i] = abonents[i];
    delete[] abonents;
    abonents = newAbonents;
}

void PhoneBook::addAbonent() {
    if (count >= capacity) resize();

    char name[100], home[20], work[20], mobile[20], info[200];
    std::cin.ignore();

    std::cout << "\nVvedite FIO: ";
    std::cin.getline(name, 100);
    std::cout << "Domashnij telefon: ";
    std::cin.getline(home, 20);
    std::cout << "Rabochij telefon: ";
    std::cin.getline(work, 20);
    std::cout << "Mobilnyj telefon: ";
    std::cin.getline(mobile, 20);
    std::cout << "Dopolnitelnaya informaciya: ";
    std::cin.getline(info, 200);

    abonents[count] = new Abonent(name, home, work, mobile, info);
    count++;
    std::cout << "Abonent dobavlen!" << std::endl;
}

void PhoneBook::removeAbonent() {
    if (count == 0) {
        std::cout << "Kniga pusta!" << std::endl;
        return;
    }

    char name[100];
    std::cin.ignore();
    std::cout << "\nVvedite FIO dlya udaleniya: ";
    std::cin.getline(name, 100);

    for (int i = 0; i < count; i++) {
        if (strcmp(abonents[i]->getFullName(), name) == 0) {
            delete abonents[i];
            for (int j = i; j < count - 1; j++) abonents[j] = abonents[j + 1];
            count--;
            std::cout << "Abonent udalen!" << std::endl;
            return;
        }
    }
    std::cout << "Ne najden!" << std::endl;
}

void PhoneBook::searchAbonent() {
    if (count == 0) {
        std::cout << "Kniga pusta!" << std::endl;
        return;
    }

    char name[100];
    std::cin.ignore();
    std::cout << "\nVvedite FIO dlya poiska: ";
    std::cin.getline(name, 100);

    for (int i = 0; i < count; i++) {
        if (strcmp(abonents[i]->getFullName(), name) == 0) {
            abonents[i]->display();
            return;
        }
    }
    std::cout << "Ne najden!" << std::endl;
}

void PhoneBook::showAll() {
    if (count == 0) {
        std::cout << "Kniga pusta!" << std::endl;
        return;
    }

    std::cout << "\n=== TELEFONNAYA KNIGA (" << count << " abonentov) ===" << std::endl;
    for (int i = 0; i < count; i++) abonents[i]->display();
}