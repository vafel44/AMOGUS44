#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    char* str;     // Указатель на динамически выделенную строку
    int length;    // Длина строки

public:
    // 1. Конструктор по умолчанию - создает строку на 80 символов
    String();

    // 2. Конструктор - создает строку произвольного размера
    String(int size);

    // 3. Конструктор - создает строку и инициализирует её строкой от пользователя
    String(const char* input);

    // 4. Конструктор копирования
    String(const String& other);

    // Деструктор
    ~String();

    // Метод для ввода строки с клавиатуры
    void inputFromKeyboard();

    // Метод для вывода строки на экран
    void display() const;

    // Получить длину строки
    int getLength() const;

    // Получить указатель на строку
    const char* getString() const;
};

#endif // STRING_H