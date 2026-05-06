#include "PhoneBook.h"
#include <windows.h>

int main() {
    // Настройка русского языка в консоли Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PhoneBook pb;
    int choice;

    do {
        std::cout << "\n1.Добавить 2.Удалить 3.Найти 4.Показать всех 0.Выход\nВыбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: pb.addAbonent(); break;
        case 2: pb.removeAbonent(); break;
        case 3: pb.searchAbonent(); break;
        case 4: pb.showAll(); break;
        case 0: std::cout << "До свидания!" << std::endl; break;
        default: std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);

    return 0;
}