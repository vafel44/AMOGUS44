#include "Person.h"

int main() {
    setlocale(LC_ALL, "Russian");

    // Конструктор с параметрами
    Date birth(15, 5, 1990);
    Person p1(1, "Петров", "Петр", "Петрович", birth);
    p1.display();

    // Конструктор по умолчанию
    Person p2;
    p2.display();

    // Конструктор копирования
    Person p3 = p1;
    p3.display();

    // Работа сеттеров
    p2.setLastName("Сидоров");
    p2.setFirstName("Сидор");
    p2.display();

    // Подсчет экземпляров
    std::cout << "\nВсего создано людей: " << Person::getInstanceCount() << std::endl;

    return 0;
}