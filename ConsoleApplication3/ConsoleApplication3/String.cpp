#define _CRT_SECURE_NO_WARNINGS  // Отключает предупреждения C4996 для strcpy

#include "String.h"
#include <cstring>

// 1. Конструктор по умолчанию - создает строку на 80 символов
String::String() : length(80) {
    str = new char[length + 1];  // +1 для символа конца строки '\0'
    str[0] = '\0';               // Пустая строка
    std::cout << "Создана пустая строка на 80 символов" << std::endl;
}

// 2. Конструктор - создает строку произвольного размера
String::String(int size) : length(size) {
    str = new char[length + 1];
    str[0] = '\0';
    std::cout << "Создана пустая строка на " << length << " символов" << std::endl;
}

// 3. Конструктор - создает строку и инициализирует её
String::String(const char* input) {
    length = static_cast<int>(strlen(input));  // Явное преобразование size_t -> int
    str = new char[length + 1];                // Выделяем память
    strcpy(str, input);                        // Копируем строку
    std::cout << "Создана строка: " << str << std::endl;
}

// 4. Конструктор копирования
String::String(const String& other) {
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);
    std::cout << "Создана копия строки: " << str << std::endl;
}

// Деструктор - освобождает выделенную память
String::~String() {
    delete[] str;
    std::cout << "Строка удалена" << std::endl;
}

// Метод для ввода строки с клавиатуры
void String::inputFromKeyboard() {
    char buffer[1000];               // Временный буфер
    std::cout << "Введите строку: ";
    std::cin.getline(buffer, 1000);

    delete[] str;                    // Освобождаем старую память
    length = static_cast<int>(strlen(buffer));  // Явное преобразование size_t -> int
    str = new char[length + 1];      // Выделяем новую память
    strcpy(str, buffer);             // Копируем
    std::cout << "Строка успешно введена!" << std::endl;
}

// Метод для вывода строки на экран
void String::display() const {
    std::cout << "Строка: " << str << std::endl;
    std::cout << "Длина: " << length << " символов" << std::endl;
}

// Получить длину строки
int String::getLength() const {
    return length;
}

// Получить указатель на строку
const char* String::getString() const {
    return str;
}