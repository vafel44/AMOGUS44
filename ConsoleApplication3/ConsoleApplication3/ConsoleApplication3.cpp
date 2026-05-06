#include "String.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");  // Для поддержки русских символов

    std::cout << "========== ДЕМОНСТРАЦИЯ РАБОТЫ КЛАССА STRING ==========\n" << std::endl;

    // 1. Демонстрация конструктора по умолчанию (80 символов)
    std::cout << "1. Конструктор по умолчанию:" << std::endl;
    String str1;
    str1.display();
    std::cout << std::endl;

    // 2. Демонстрация конструктора с размером (20 символов)
    std::cout << "2. Конструктор с произвольным размером (20 символов):" << std::endl;
    String str2(20);
    str2.display();
    std::cout << std::endl;

    // 3. Демонстрация конструктора с инициализацией строкой
    std::cout << "3. Конструктор с инициализацией строкой:" << std::endl;
    String str3("Привет, мир!");
    str3.display();
    std::cout << std::endl;

    // 4. Демонстрация конструктора копирования
    std::cout << "4. Конструктор копирования:" << std::endl;
    String str4 = str3;
    str4.display();
    std::cout << std::endl;

    // 5. Демонстрация ввода строки с клавиатуры
    std::cout << "5. Ввод строки с клавиатуры:" << std::endl;
    String str5;
    std::cin.ignore();  // Очищаем буфер перед вводом
    str5.inputFromKeyboard();
    str5.display();
    std::cout << std::endl;

    // 6. Демонстрация методов getLength и getString
    std::cout << "6. Демонстрация геттеров:" << std::endl;
    std::cout << "Длина строки str3: " << str3.getLength() << std::endl;
    std::cout << "Содержимое строки str3: " << str3.getString() << std::endl;
    std::cout << std::endl;

    std::cout << "========== КОНЕЦ ДЕМОНСТРАЦИИ ==========" << std::endl;

    return 0;
}